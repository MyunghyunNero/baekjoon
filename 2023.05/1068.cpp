#include <iostream>
#include <vector>
using namespace std;
int n;
int root;
int del;
int ans;
vector<int> v[51];
void dfs(int r){
    int len=v[r].size();
    if(del==r){
        return;
    }
    if(len==0){
        ans++;
        return;
    }else if(len==1 && v[r][0]==del){
        ans++;
        return;
    }
    for(int i=0;i<len;i++){
        dfs(v[r][i]);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a==-1){
            root=i;
        }else{
            v[a].push_back(i);
        }
    }
    cin>>del;
    dfs(root);
    cout<<ans;
}