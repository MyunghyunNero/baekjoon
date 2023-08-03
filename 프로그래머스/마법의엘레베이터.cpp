#include <string>
#include <vector>
#include <queue>
using namespace std;

int ans;

int solution(int storey) {
    int answer = 0;
    while(storey>0){
        if(storey%10>10-storey%10){
            ans+=10-storey%10;
            storey/=10;
            storey+=1;
        }else if(storey%10==5){
            ans+=storey%10;
            storey/=10;
            if(storey%10>=5){
                storey+=1;
            }
        }else{
            ans+=storey%10;
            storey/=10;
        }
    }
    return ans;
}