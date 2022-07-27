#include <iostream>
using namespace std;
int dp[2001][20001];
int arr[20001];
int n,m;
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        dp[i][i]=1;
        if(i!=1&&arr[i]==arr[i-1]){
            dp[i-1][i]=1;
        }
    }
    for(int i=2;i<n;i++){
        for(int j=1;j+i<=n;j++){
            if(arr[j]==arr[i+j] && dp[j+1][i+j-1]==1){
                dp[j][i+j]=1;
            }
        }
    }
    cin>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        cout<<dp[a][b]<<'\n';
    }
}