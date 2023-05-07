#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector<int> v[1001];
int check[1001];
int n,m;
void dfs(int s,int cnt){
    if(check[s]<cnt){
		check[s]=cnt;
	}
    for(int i=0;i<v[s].size();i++){
        if(check[v[s][i]]<cnt+1){  
            dfs(v[s][i],cnt+1);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(check[i]==0)
            dfs(i,1);
    }
    for(int i=1;i<=n;i++){
        cout<<check[i]<<' ';
    }
}