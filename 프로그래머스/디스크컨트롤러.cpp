#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        if(a[1]>b[1]) {
            return true;
        }
        return false;
    }
};
priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(),jobs.end());
    int len = jobs.size();
    int time = 0;
    for(int i = 0 ;i < len; i++) {
        if(time <= jobs[i][0]) {
            if(pq.empty()){
                time = jobs[i][0]+jobs[i][1];
                answer += jobs[i][1];
                continue;
            }else {
                 while(!pq.empty() && time <= jobs[i][0]) {
                    vector<int> tmp = pq.top();
                    pq.pop();
                    time += tmp[1];
                    answer +=(time - tmp[0]);
                }
            }
        }
        pq.push(jobs[i]);
    }
    
    while(!pq.empty()) {
        vector<int> tmp = pq.top();
        pq.pop();
        if(time > tmp[0]) {
            time += tmp[1];
            answer +=(time - tmp[0]);
        }else {
            time = tmp[0]+tmp[1];
            answer += tmp[1];
        }
    }
    answer/=len;
    return answer;
}
