#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int T,n,m,t,s,g,h;
int dists[2010];
int distg[2010];
int disth[2010];
int distgh;
vector<pair<int,int>> arr[2010];
vector<int> target;
void dijkstra(int start,int dist[2010]){ 
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
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    for(int i=0;i<T;i++){
        for(int k=0;k<2010;k++){
            arr[k].clear();
            dists[k]=9999999;
            distg[k]=9999999;
            disth[k]=9999999;
        }
        target.clear();
        cin>>n>>m>>t;
        cin>>s>>g>>h;
        for(int k=0;k<m;k++){
            int a,b,c;
            cin>>a>>b>>c;
            arr[a].push_back({b,c});
            arr[b].push_back({a,c});
        }
        for(int k=0;k<t;k++){
            int a;
            cin>>a;
            target.push_back(a);
        }
        dijkstra(s,dists);
        dijkstra(g,distg);
        distgh=distg[h];
        dijkstra(h,disth);
        sort(target.begin(),target.end());
        for(int k=0;k<target.size();k++){
            int temp=target[k];
            if(dists[temp]==dists[g]+distgh+disth[temp]){
                cout <<temp<<" ";
            }
            else if(dists[temp]==dists[h]+distgh+distg[temp]){
                cout << temp<<' ';
            }
        }
        cout <<'\n';
    }
}