#include <string>
#include <vector>
#include <iostream>
using namespace std;
int calSize(int cnt) {
    int res=1;
    while(cnt/10) {
        cnt/=10;
        res++;
    }
    return res;
}
int solution(string s) {
    int len = s.size();
    int answer = len;
    for(int i=1;i<=len;i++) {
        string start = s.substr(0,i);
        int tmpLen = 0;
        int cnt = 1;
        for(int k=i;k<len;k+=i) {
            string cmp = s.substr(k,i);
            if(cmp.size()!=i) break;
            if(start == cmp) {
                cnt++;
            } else {
                if(cnt == 1) tmpLen +=i;
                else {
                    tmpLen +=(i+calSize(cnt));
                }
                start = cmp;
                cnt=1;
            }
        }
        if(cnt == 1) tmpLen +=i;
        else tmpLen +=(i+calSize(cnt));
        answer = min(tmpLen+len%i,answer);
    }
    return answer;
}