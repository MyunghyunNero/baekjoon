#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int aIdx =0;
    int bIdx =0;
    int endSize = B.size();
    while(aIdx < endSize && bIdx < endSize) {
        if(A[aIdx] < B[bIdx]){
            aIdx++;
            bIdx++;
            answer++;
        }else{
            bIdx++;
        }
    }
    return answer;
}