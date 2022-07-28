#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int check[100001];
int cnt;
int n,m,r;
void dfs(vector<vector<int>> &v,int start){
    if(check[start]!=0){
        return;
    }
    check[start]=++cnt;
    for(int i=0;i<v[start].size();i++){
        if(check[v[start][i]]==0){
            dfs(v,v[start][i]);
        }
    }
}
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    cin>>n>>m>>r;
    vector<vector<int>> v(n+1);
    for(int i=1;i<=m;i++){
        int s,e;
        cin>>s>>e;
        v[s].push_back(e);
        v[e].push_back(s);
    }
    for(int i=1;i<=n;i++){
        sort(v[i].begin(),v[i].end(),greater<>());
    }
    dfs(v,r);
    for(int i=1;i<=n;i++){
        cout <<check[i]<<'\n';
    }
}