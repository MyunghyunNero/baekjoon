#include <iostream>
using namespace std;
int dp[10001];
int a;
int n,k;
int main(){
    cin>>n>>k;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        cin>>a;
        for(int j=0;j+a<=k;j++){
            dp[j+a]+=dp[j];
        }
    }
    cout<<dp[k];

}