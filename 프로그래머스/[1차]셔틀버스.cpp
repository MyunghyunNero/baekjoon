#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
vector<int> timeArr;
queue<int> q;
int check[61];
vector<vector<int>> ansArr;
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int startTime = 60*9;
    for(string str : timetable) {
        int hour = stoi(str.substr(0,2));
        int min = stoi(str.substr(3,2));
        timeArr.push_back(hour*60 + min);
    }
    sort(timeArr.begin(),timeArr.end());
    int con = 0;
    int curTime = startTime;
    int idx=0;
    for(int i=0;i<n;i++) {
        vector<int> tmp;
        for(int j=0;j<m;j++) {
            if(timeArr[idx] <= curTime && idx<timeArr.size()) {
                tmp.push_back(timeArr[idx]);
                idx++;
            }else {
                break;
            }
        }
        ansArr.push_back(tmp);
        curTime += t;
    }
    curTime = startTime;
    for(int i=0;i<n;i++) {
        if(ansArr[i].size()<m) {
            con = curTime;
        }else {
            con = ansArr[i][m-1]-1;
        }
        curTime += t;
    }
    string hourStr = to_string(con/60);
    if(hourStr.size()<2) hourStr = "0" + hourStr;
    string minStr = to_string(con%60);
    if(minStr.size()<2) minStr = "0" + minStr;
    answer = hourStr + ":" + minStr;
    return answer;
}