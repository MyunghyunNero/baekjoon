#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

long long countint(int r){
    long long cnt=r;
    for(int i=1;i<r;i++){
        cnt+=(long long)(sqrt(1LL*r*r-1LL*i*i));
    }
    return cnt*4+1;
}
long long countinside(int r){
    long long cnt=r-1;
    for(int i=1;i<r;i++){
        long long tmp=(long long)(sqrt(1LL*r*r-1LL*i*i));
        if(1LL*tmp*tmp+1LL*i*i == 1LL*r*r) tmp=tmp-1;
        cnt+=tmp;
    }
    return 4*cnt+1;
}
long long solution(int r1, int r2) {
    
    long long answer = countint(r2)-countinside(r1);
    return answer;
}