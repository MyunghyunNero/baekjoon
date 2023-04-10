#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n,m;
set<int> s;
vector<int> v;
void dfs(int idx){
    if(idx==m){
        for(int i=0;i<m;i++){
            cout<<v[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(auto iter=s.begin();iter!=s.end();iter++){
        v.push_back(*iter);
        dfs(idx+1);
        v.erase(v.end());
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        s.insert(a);
    }
    dfs(0);
}