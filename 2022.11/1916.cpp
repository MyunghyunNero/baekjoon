#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 987654321
int n,m;
int start,e;
int dist[1001];
vector<pair<int,int>> arr[1001];
void dijkstra(int start){
    dist[start]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({dist[start],start});
    while(!q.empty()){
        int distNow = q.top().first;
        int node = q.top().second;
        q.pop();
        
        if(dist[node]<distNow) continue;
        for(int i=0;i<arr[node].size();i++){
            int distNext = arr[node][i].first;
            int nodeNext = arr[node][i].second;
            if( dist[nodeNext]> dist[node]+distNext){
                dist[nodeNext] = dist[node] + distNext;
                q.push({dist[nodeNext],nodeNext});
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[a].push_back({c,b});
    }
    for (int i = 1; i <= n; i++) 
		dist[i] = INF;
    cin>>start>>e;
    dijkstra(start);
    cout << dist[e];
}