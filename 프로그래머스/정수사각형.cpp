#include <string>
#include <vector>

using namespace std;
int dp[501][501];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[0][0]=triangle[0][0];
    for(int i = 1 ; i<triangle.size();i++){
        dp[i][0]=dp[i-1][0]+triangle[i][0];
        int len = triangle[i].size();
        dp[i][len-1]+=dp[i-1][len-2]+triangle[i][len-1];
        for(int j = 1 ; j<triangle[i].size()-1;j++) {
            int maxV = max(dp[i-1][j-1],dp[i-1][j]);
            dp[i][j]=maxV+triangle[i][j];
        }
    }
    int lastIndex = triangle.size()-1;
    for(int i =0;i <= lastIndex ; i++) {
        answer = max(answer,dp[lastIndex][i]);
    }
    return answer;
}