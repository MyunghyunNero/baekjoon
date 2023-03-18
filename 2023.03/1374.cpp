#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<pair<int,int>> v;
priority_queue<int,vector<int>,greater<int>> q;
int ans;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({b,c});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        if(!q.empty() && q.top()<=v[i].first){
            q.pop();
        }
        q.push(v[i].second);
        if(q.size()>ans) ans=q.size();
    }
    cout<<ans;
}