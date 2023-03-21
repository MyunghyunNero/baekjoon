#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int dp[21][10001];
int main(){
    int t;
    cin>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        int n;
        cin>>n;
        vector<int> coin;
        for(int i=0;i<n;i++){
            int c;
            cin>>c;
            coin.push_back(c);
            
        }
        int m;
        cin>>m;
        for(int i=1;i<=n;i++){
            int coinV=coin[i-1];
            
            for(int j=1;j<=m;j++){
                if(j<coinV){
                    dp[i][j]=dp[i-1][j];
                }else if(j==coinV){
                    dp[i][coinV]=dp[i-1][coinV]+1;
                }else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-coinV];
                }
            }
        }
        cout<<dp[n][m]<<'\n';
    }
}