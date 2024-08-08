#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
priority_queue<int> pq;
int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    bool check = false;
    for(int i=0;i<enemy.size();i++) {
        pq.push(enemy[i]);
        n-=enemy[i];
        if(n < 0) {
            if(k <= 0) {
                check = true;
                answer = i;
                break;
            }else {
                int value = pq.top();
                pq.pop();
                n+=value;
                k--;
            }
        }
        
    }
    if(!check) {
        answer = enemy.size();
    }
    return answer;
}