#include <iostream>
#include <vector>
using namespace std;
bool check[101];
int ans;
void dfs(vector<vector<int>>& v,int x){        //dfs 벡터
    ans++;
    check[x]=true;
    int len=v[x].size();
    for(int i=0;i<len;i++){
        if(check[v[x][i]]==false){         
            dfs(v,v[x][i]);
        }
    }
}
int main(){
    int n,m;
    cin >> n>>m;
    vector<vector<int>> v(n+1);
    while(m--){
        int x,y;
        cin >> x>>y;
        v[x].push_back(y);           //양방향 그래프이기 때문에 둘다 들어가기
        v[y].push_back(x);
    }
    dfs(v,1);
    cout <<ans-1;
}