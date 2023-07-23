#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int changeTime(string s){
    int sum=60*stoi(s.substr(0,2))+stoi(s.substr(3,5));
    return sum;
}
bool cmp(vector<string> s1, vector<string> s2){
    if(changeTime(s1[0])<changeTime(s2[0])){
        return true;
    }else{
        return false;
    }
}
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    sort(book_time.begin(),book_time.end(),cmp);
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<book_time.size();i++){
        int starttime=changeTime(book_time[i][0]);
        int endtime=changeTime(book_time[i][1])+10;
        if(pq.empty()) pq.push(endtime);
        else{
            int time=pq.top();
            if(starttime>=time){
                pq.pop();
                pq.push(endtime);
                
            }else{
                pq.push(endtime);
            }
        }
    }
    return pq.size();
}