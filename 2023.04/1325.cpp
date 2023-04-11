#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int cntarr[10001];
vector<int> v[10001];
bool visited[10001];
int cnt=0;
void dfs(int idx){
    visited[idx]=true;
    for(int i=0;i<v[idx].size();i++){
        if(!visited[v[idx][i]]){
            cnt++;
            visited[v[idx][i]]=true;
            dfs(v[idx][i]);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[b].push_back(a);
    }
    int maxC=0;
    for(int i=1;i<=n;i++){
        memset(visited,false,sizeof(visited));
        cnt=0;
        dfs(i);
        maxC=max(maxC,cnt);
        cntarr[i]=cnt;
    }
    for(int i=1;i<=n;i++){
        if(cntarr[i]==maxC){
            cout<<i<<' ';
        }
    }
}
