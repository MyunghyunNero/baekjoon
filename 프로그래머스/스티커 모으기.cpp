#include <iostream>
#include <vector>
#include <iostream>
using namespace std;
int dp1[100001];
int dp2[100001];
int solution(vector<int> sticker)
{
    int answer =0;
    dp1[0]=sticker[0];
    dp1[1]=sticker[0];
    int len = sticker.size();
    if(len==1){
        return sticker[0];
    }else if(len ==2){
        return max(sticker[0],sticker[1]);
    }
    for(int i=2;i<len-1;i++) {
        dp1[i]= max(dp1[i-1],dp1[i-2]+sticker[i]);
    }
    dp2[0]=0;
    dp2[1]=sticker[1];
    for(int i=2;i<len;i++) {
        dp2[i]= max(dp2[i-1],dp2[i-2]+sticker[i]);
    }
    

    answer = max(dp1[len-2],dp2[len-1]);
    return answer;
}