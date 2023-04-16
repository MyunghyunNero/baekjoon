#include <iostream>
#include <queue>
using namespace std;
int arr[1001][1001];
long long dp[1001][1001];
int n,m,k;

int main(){
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        arr[x][y]=-1;
    }
    dp[1][1]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i%2==1){
                long long one= (arr[j-1][i-1]==-1) ? 0 : dp[j-1][i-1];
                long long two=(arr[j-1][i]==-1) ? 0 : dp[j-1][i];
                long long three=(arr[j][i-1]==-1) ? 0 : dp[j][i-1];
                dp[j][i]=(one+two+three+dp[j][i])%1000000007;
            }else{
                long long one= (arr[j-1][i]==-1) ? 0 : dp[j-1][i];
                long long two=(arr[j][i-1]==-1) ? 0 : dp[j][i-1];
                long long three=(arr[j+1][i-1]==-1) ? 0 : dp[j+1][i-1];
                dp[j][i]=(one+two+three)%1000000007;
            }
        }
    } 
    cout<<dp[n][m];
}