#include <iostream>
#include <string>
using namespace std;
int dp[2501][2501];
int solution(string s)
{
    int answer=1;
    int len = s.size(); 
    for(int i=0;i<len;i++) {
        dp[i][i] = true;
    }
    for(int i=0;i<len-1;i++) {
        if(s[i]==s[i+1]) {
            answer =2;
            dp[i][i+1] = true;
        }
    }
    for(int i = 3;i<=len;i++) {
        for(int start=0;start<=len-i;start++) {
            int end = start + i -1;
            if(s[start]==s[end] && dp[start+1][end-1]) {
                dp[start][end]=true;
                answer=i;
            }
        }
    }
    return answer;
}