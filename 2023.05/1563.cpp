#include <iostream>
using namespace std;
#define MOD 1000000
int n;
int dp[2][3][1001];
int ans;
int main(){
    cin>>n;
    dp[0][0][1]=1;
    dp[1][0][1]=1;
    dp[0][1][1]=1;
    for(int i=2;i<=n;i++){
        dp[0][0][i]=dp[0][0][i - 1] + dp[0][1][i - 1] + dp[0][2][i - 1];
        dp[0][1][i] = dp[0][0][i - 1];
        dp[0][2][i] = dp[0][1][i - 1];
        dp[1][0][i] = dp[0][0][i - 1] + dp[0][1][i - 1] + dp[0][2][i - 1] + dp[1][0][i - 1] + dp[1][1][i - 1] + dp[1][2][i - 1];
        dp[1][1][i] = dp[1][0][i - 1];
        dp[1][2][i] = dp[1][1][i - 1];
        for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				//각 연산에 대해서 100만으로 나머지 연산
				dp[j][k][i] %= MOD;
			}
		}
    }
    for (int j = 0; j < 2; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			//ans에 N번째 날의 지각0~1, 연속 결석0~2 을 모두 더해줌
			ans+=dp[j][k][n];
		}
	}
    ans %= MOD;
	cout << ans << '\n';
}