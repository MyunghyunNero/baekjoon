#include <string>
#include <vector>
#include <cmath>
using namespace std;
int findNum(long long n) {
    if(n==1) return 0;
    long long tmp = 1;
    for(long long i = 2;i<=sqrt(n);i++) {
        if(n%i==0) {
            tmp = i;
            if(n/i <= 10000000) {
                tmp = n/i;
                break;
            }
        }
    }
    return tmp;
}
vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for(long long i = begin ; i<=end;i++) {
        answer.push_back(findNum(i));
    }
    return answer;
}