#include<iostream>
#include <algorithm>
using namespace std;
int dp[501][501];
int cost[501];
int sum[501];
int t, k;
int main() {
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> k;
        for(int i=1;i<=k;i++){
            cin>>cost[i];
            sum[i]=sum[i-1]+cost[i];
        }
        for(int i=1;i<k;i++){
            for(int j=1;j+i<=k;j++){
                dp[j][j+i]=100000007;
                for(int mid=j;mid<=j+i;mid++){
                    dp[j][j+i]=min(dp[j][j+i],dp[j][mid]+dp[mid+1][j+i]+sum[j+i]-sum[j-1]);
                }
            }   
        }
        cout << dp[1][k]<<'\n';
    }
}