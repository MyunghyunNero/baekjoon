#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    int len=sequence.size();
    long long sum=0;
    int idx=1;
    for(int i=0;i<len;i++){
        if(sum+idx*sequence[i]>0){
            sum+=sequence[i]*idx;
        }else{
            sum=0;
        }
        answer=max(answer,sum);
        idx*=-1;
    }
    sum=0;
    idx=-1;
    for(int i=0;i<len;i++){
        if(sum+idx*sequence[i]>0 ){
            sum+=sequence[i]*idx;
        }else{
            sum=0;
        }
        answer=max(answer,sum);
        idx*=-1;
    }
    return answer;
}