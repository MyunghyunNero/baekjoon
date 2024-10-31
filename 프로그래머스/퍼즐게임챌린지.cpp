#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> diff;
vector<int> t;

long long checkSolveTime(long long limit, int level) {
    
    long long sum = t[0];
    for(int i=1;i<t.size();i++) {
        int retry = 0;
        if(diff[i]>level) {
            retry = diff[i] - level;
        }
        sum += (retry*(t[i-1]+t[i]) +t[i]);
    }
    return sum;
}
int binarySearch(long long limit) {
    int left = 1;
    int right = 100000;
    while(left <= right) {
        int mid = (left + right)/2;
        if(limit>=checkSolveTime(limit,mid)) {
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return left;
}
int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    diff = diffs;
    t = times;
    answer = binarySearch(limit);
    return answer;
}