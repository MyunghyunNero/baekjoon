#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    long long idx =10; 
    while(n) {
        int num = n%idx;
        answer.push_back(num);
        n/=10;
    }
    return answer;
}