#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<>> q;
int n;
int ans;
int main(){
    vector<pair<int,int>> v;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        int s=v[i].first;
        int e=v[i].second;
        if(q.empty() || q.top()>s){
            q.push(e);
        }else if(q.top()<=s){
            q.pop();
            q.push(e);
        }
        if(ans<q.size()){
            ans=q.size();
        }
    }
    cout<<ans;
}