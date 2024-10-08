#include <string>
#include <vector>

using namespace std;
long long dp[5001];
int solution(int n) {
    int answer = 0;
    dp[2]=3;
    for(int i=4;i<=n;i+=2) {
        dp[i] = dp[i-2]*3;
        for(int j=i-4;j>=0;j-=2) {
            dp[i] += dp[j]*2;
        }
        dp[i]+=2;
        dp[i]%=1000000007;
    } 
    return dp[n];
}