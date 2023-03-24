#include <iostream>
#include <cstring>
using namespace std;
long long dp[31][31];
int n;
int main(){
    while(1){
        cin>>n;
        if(n==0){
            break;
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(i==j){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        cout<<dp[n][n]<<'\n';
    }
}