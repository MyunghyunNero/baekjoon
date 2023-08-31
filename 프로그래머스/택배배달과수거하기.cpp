#include <string>
#include <vector>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    long long give=0;
    long long take=0;
    for(int i = n-1 ; i >= 0 ; i--){
        if(deliveries[i]!=0 || pickups[i]!=0){
            long long mCnt=0;
            long long loop=0;
            if(give < deliveries[i] || take < pickups[i]){
                mCnt = max(deliveries[i]-give,pickups[i]-take);
                loop =mCnt % cap ==0 ? mCnt/cap : (mCnt/cap+1);
                give += loop*cap;
                take += loop*cap;
            }
            give -= deliveries[i];
            take -= pickups[i];
            if(loop!=0){
                answer +=(i+1)*2*(loop);
            }
        }
    }
    return answer;
}