#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int INF = 987654321;
vector<pair<int,int>> v[201];
int dist[201];
void init() {
    for(int i=0;i<201;i++) {
        dist[i] = INF;
    }
}
void dijkstra(int start) {
    init();
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    dist[start]=0;
    while(!pq.empty()) {
        int d = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for(int i = 0;i < v[cur].size();i++) {
            int next = v[cur][i].first;
            int nCost = v[cur][i].second;
            if(dist[next] > nCost + d){
                dist[next] = nCost + d;
                pq.push({-dist[next] , next});
            }
        }
    }
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 987654321;
    for(int i=0;i<fares.size();i++) {
        v[fares[i][0]].push_back({fares[i][1],fares[i][2]});
        v[fares[i][1]].push_back({fares[i][0],fares[i][2]});
    }
    dijkstra(s);
    vector<int> dist_s(dist, dist+n+1);
    
    dijkstra(a);
    vector<int> dist_a(dist,dist+n+1);
    
    dijkstra(b);
    vector<int> dist_b(dist,dist+n+1);
    for(int i=1;i<=n;i++){
        int mid = dist_s[i];
        int aDest = dist_a[i];
        int bDest = dist_b[i];
        if(mid == INF || aDest == INF || bDest == INF) continue;
        answer = min(answer, mid + aDest + bDest);
    }
    return answer;
}