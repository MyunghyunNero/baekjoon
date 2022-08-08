#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n;
bool visited[10002];
vector<pair<int,int>> v[10002];
int ans=0; //지름 길이
int endp=0; //지름에 해당하는 끝점
void dfs(int cur,int len){
    if(visited[cur])
        return;
    visited[cur]=true;
    if(ans<len){
        ans=len;
        endp=cur;
    }
    
    for(int i=0;i<v[cur].size();i++){
        dfs(v[cur][i].first,len+v[cur][i].second);
    }
}
 
int main(){
    cin>>n;
    int a,b,c;
    for(int i=0;i<n-1;i++){
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    dfs(1,0);
    ans=0;
    memset(visited,0,sizeof(visited));
    dfs(endp,0);
    cout<<ans<<endl;
    return 0;
}