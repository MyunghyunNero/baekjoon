#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dist[20010];
int v,e,v1,v2;
long long stov1,stov2,v1tov2,v1tov,v2tov;
long long ans=999999999;
vector<pair<int,int>> arr[20010];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
void search(int start){
    for(int i=1;i<=v;i++){
        dist[i]=999999999;
    }
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
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[a].push_back({b,c});
        arr[b].push_back({a,c});
    }
    cin >>v1>>v2;
    search(1);
    stov1=dist[v1];
    stov2=dist[v2];
    search(v1);
    v1tov2=dist[v2];
    v1tov=dist[v];
    search(v2);
    v2tov+=dist[v];
    ans=min(stov1+v1tov2+v2tov,stov2+v1tov2+v1tov);
    if(ans>=999999999){
        cout <<-1;
    }else{
        cout <<ans;
    }
}