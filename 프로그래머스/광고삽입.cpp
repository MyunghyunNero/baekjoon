#include <string>
#include <vector>
#include <iostream>

using namespace std;
long long dp[360001];
int tol(string time) {
    int hour = stoi(time.substr(0,2)) * 3600;
    int min = stoi(time.substr(3,2))*60;
    int second = stoi(time.substr(6,2));
    return hour + min + second;
} 
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    for(string log : logs) {
        int st = tol(log.substr(0,8));
        int ed = tol(log.substr(9,8));
        dp[st+1]++;
        dp[ed+1]--;
    }
    long long playTime = tol(play_time);
    for(int i=1;i<=playTime;i++) {
        dp[i] += dp[i-1];
    }
    long long maxTotalTime = 0;
    long long curTotalTime = 0;
    long long avTime = tol(adv_time);
    for(int i=1;i<=avTime;i++) {
        maxTotalTime += dp[i];
        curTotalTime += dp[i];
    }
    long long idx = 0;
    for(int i = 2;i+avTime-1<=playTime;i++) {
        curTotalTime +=(dp[i+avTime-1]-dp[i-1]);
        if(curTotalTime>maxTotalTime) {
            idx = i-1;
            maxTotalTime = curTotalTime;
        }
    }
    string hr = to_string(idx / 3600);
    if(hr.length() == 1) hr = "0" + hr;
    idx %= 3600;
    string mn = to_string(idx / 60);
    if(mn.length() == 1) mn = "0" + mn;
    idx %= 60;
    string sc = to_string(idx);
    if(sc.length() == 1) sc = "0" + sc;
    return hr + ":" + mn + ":" + sc; 
}