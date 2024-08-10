#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for(long long i=0;i<=d;i+=k) {
        int value = sqrt((long long)d*d - (long long)i*i);
        answer+=(value/k)+1;
    }
    return answer;
}