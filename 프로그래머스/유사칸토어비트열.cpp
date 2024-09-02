#include <string>
#include <vector>

using namespace std;
bool check(long long n) {
    if(n%5==2) return false;
    if(n<=4) return true;
    return check(n/5);
}
int solution(int n, long long l, long long r) {
    int answer = 0;
    for(long long i=l-1 ;i<r;i++) {
        if(check(i)) {
            answer++;
        }
    }
    return answer;
}