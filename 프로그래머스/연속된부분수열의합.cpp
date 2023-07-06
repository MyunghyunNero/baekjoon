#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    answer[0]=0;
    answer[1]=1000000;
    int len=1000000;
    int start=0;
    int sum=0;
    for(int i=0;i<sequence.size();i++){
        sum+=sequence[i];
        while(sum>k){
            sum-=sequence[start];
            start++;
        }
        if(sum==k){
            if(i-start<len){
                len=i-start;
                answer[0]=start;
                answer[1]=i;
            }
        }
    }
    return answer;
}