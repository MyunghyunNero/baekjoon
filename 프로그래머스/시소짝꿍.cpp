#include <string>
#include <vector>
#include <algorithm>
using namespace std;
long long arr[1001];
long long solution(vector<int> weights) {
    long long answer = 0;
    for(int i=0;i<weights.size();i++){
        arr[weights[i]]++;
    }
    for(int i=100;i<=1000;i++){
        if(arr[i]==0) continue;
        if(arr[i] >1){
            answer+=(arr[i]*(arr[i]-1))/2;
        }
        if(i%2==0){
            if(3*i/2 <=1000)
                answer+=(arr[3*i/2] * arr[i]);
        }
        if(2*i<=1000)
                answer+=(arr[i*2]*arr[i]);
        if(i%3==0){
            if(4*i/3<=1000)
                answer+=(arr[4*i/3]*arr[i]);
        }
    }
    return answer;
}