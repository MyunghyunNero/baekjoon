#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ans;
int n;
vector<pair<int,int>> v;
void dfs(int idx){
	if(idx==n){
        int cnt=0;
        for(int i=0;i<v.size();i++){
            if(v[i].first<=0){
                cnt++;
            }
        }
        ans=max(cnt,ans);
        return;
    }
    if(v[idx].first<=0){
        dfs(idx+1);
        return;
    }
    bool b=false;
    for(int i=0;i<v.size();i++){
        if(i==idx || v[i].first<=0) continue;
        v[idx].first-=v[i].second;
        v[i].first-=v[idx].second;
        b=true;
        dfs(idx+1);
        v[idx].first+=v[i].second;
        v[i].first+=v[idx].second;
    }
    if(!b){
    	dfs(idx+1);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    dfs(0);
    cout<<ans;
}