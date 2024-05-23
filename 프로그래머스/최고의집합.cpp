#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(s<n) {
        answer.push_back(-1);
    }else{
        int val = s/n;
        int remain = s%n;
        for(int i=0;i<n-remain;i++) {
            answer.push_back(val);
        }
        for(int i=0;i<remain;i++){
            answer.push_back(val+1);
        }
    }
    return answer;
}