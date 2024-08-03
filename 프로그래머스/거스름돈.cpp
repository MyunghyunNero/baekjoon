#include <string>
#include <vector>
#include <iostream>
using namespace std;
int dp[100001];
int solution(int n, vector<int> money) {
    int answer = 0;
    int len = money.size();
    dp[0]=1;
    for(int coin : money) {
        for(int j=coin;j<=n;j++) {
            dp[j] += dp[j-coin]%1000000007;
        }
    }
            
    return dp[n];
}