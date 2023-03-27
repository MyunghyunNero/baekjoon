#include <iostream>
using namespace std;
int n;
int dp[1000001];
int ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        dp[a]=dp[a-1]+1;
        ans=max(ans,dp[a]);
    }
    cout<<n-ans;
}   