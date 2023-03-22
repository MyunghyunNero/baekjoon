#include <iostream>
#include <vector>
using namespace std;
int dp[1500001];
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b; 
        v.push_back({a,b});
    }
    for(int i=0;i<=n;i++){
        int t=v[i].first;
        int value=v[i].second;
        if(dp[i]<dp[i-1]){
            dp[i]=dp[i-1];
        }
        if(i+t<=n){
            dp[i+t]=max(dp[i+t],dp[i]+value);
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans;

}