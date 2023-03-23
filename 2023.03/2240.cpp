#include <iostream>
using namespace std;
int t,w;
int list[1001];
int dp[31][2][1001];
int main(){
    cin>>t>>w;
    for(int i=1;i<=t;i++){
        cin>>list[i];
    }
    for(int i=0;i<=w;i++){
        for(int j=1;j<=t;j++){
            if(i==0){
                dp[i][0][j]=dp[i][0][j-1]+(list[j]==1);
            }else{
                dp[i][0][j]=max(dp[i][0][j-1]+(list[j]==1),dp[i-1][1][j-1]+(list[j]==1));
                dp[i][1][j]=max(dp[i][1][j-1]+(list[j]==2),dp[i-1][0][j-1]+(list[j]==2));
            }
        }
    }
    int ans=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<=w;j++){
            ans=max(ans,dp[j][i][t]);
        }
    }
    cout<<ans;
}