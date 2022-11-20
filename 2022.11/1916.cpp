#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 987654321
int n,m;
int start,e;
int dist[1001];
bool check[1001];
vector<pair<int,int>> arr[1001];
void dijkstra(int start){
    dist[start]=0;
    priority_queue<pair<int,int>> q;
    q.push({dist[start],start});
    check[node]=true;
    while(!q.empty()){
        int distNow = q.top().first;
        int node = q.top().second;
        q.pop();
        for(int i=0;i<arr[node].size();i++){
            int distNext = arr[node][i].first;
            int nodeNext = arr[node][i].second;
            if(!check[nodeNext] && dist[nodeNext]> dist[node]+distNext){
                dist[nodeNext] = dist[node] + distNext;
                q.push({dist[nodeNext],nodeNext});
                check[nodeNext]=true;
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        arr[a].push_back(make_pair(c,b));
    }
    for (int i = 1; i <= n; i++) 
		dist[i] = INF;
    cin>>start>>e;
    dijkstra(start);
    cout << dist[e];
}