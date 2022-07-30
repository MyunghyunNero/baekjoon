#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dist[20010];
int v,e,start;
vector<pair<int,int>> arr[20010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>v>>e>>start;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[a].push_back({b,c});
    }
    for(int i=1;i<=v;i++){
        dist[i]=999999999;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,start});
    dist[start]=0;
    while(!q.empty()){
        int w=q.top().first;
        int x=q.top().second;
        q.pop();
        for(int i=0;i<arr[x].size();i++){
            int nx=arr[x][i].first;
            int nw=arr[x][i].second;
            if(dist[nx]>w+nw){
                dist[nx]=w+nw;
                q.push({dist[nx],nx});
            }
        }
    }
    for(int i=1;i<=v;i++){
        if(dist[i]==999999999){
            cout<<"INF"<<'\n';
        }else{
            cout << dist[i]<<'\n';
        }
    }
}