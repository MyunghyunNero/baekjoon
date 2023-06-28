#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n,m;
vector<pair<int,int>> v[1001];
bool visited[1001];
long long ans;
void dfs(int s,int target,long long dis){
    if(s==target){
        ans=dis;
        return;
    }
    for(int i=0;i<v[s].size();i++){
        if(!visited[v[s][i].first]){
            visited[v[s][i].first]=true;
            dfs(v[s][i].first,target,dis+v[s][i].second);
            visited[v[s][i].first]=false;
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    while(m--){
        memset(visited,false,sizeof(visited));
        int s,e;
        cin>>s>>e;
        ans=0;
        visited[s]=true;
        dfs(s,e,0);
        cout<<ans<<'\n';

    }
}