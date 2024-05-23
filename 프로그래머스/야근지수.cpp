#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int> pq;
long long solution(int n, vector<int> works) {
    long long answer = 0;
    long long sum = 0;
    int wSize = works.size();
    for(int work : works) {
        pq.push(work);
    }
    for(int i=0;i<n;i++) {
        int tmp = pq.top();
        pq.pop();
        if(tmp>=1) {
            pq.push(tmp-1);
        }else{
            pq.push(0);
        }
    }
    while(!pq.empty()){
        int tmp = pq.top();
        answer += (tmp*tmp);
        pq.pop();
    }
    return answer;
}