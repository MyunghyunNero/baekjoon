#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1=0;
    long long sum2=0;
    queue<int> q1;
    queue<int> q2;
    for(int x : queue1){
        q1.push(x);
        sum1+=x;
    }
    for(int x : queue2){
        q2.push(x);
        sum2+=x;
    }
    if(((sum1+sum2)%2)==1) return -1;
    while(sum1!=sum2){
        answer++;
        if(answer>600001) return -1;
        if(sum1>sum2){
            int x = q1.front();
            q1.pop();
            q2.push(x);
            sum1-=x;
            sum2+=x;
        }else{
            int x=q2.front();
            q2.pop();
            q1.push(x);
            sum1+=x;
            sum2-=x;
        }
    }
    return answer;
}