#include <string>
#include <vector>
#include <iostream>
using namespace std;
string invertStr(int num, int n) {
    string s = "";
    while(num/n!=0){
        string tmp = s;
        if(num%n>9) {
            s=(char)('A'+(num%n-10));
        }else{
            s=(char)(num%n+'0');
        }
        s+=tmp;
        num/=n;
    }
    string tmp= s;
    if(num%n>9) {
        s=(char)('A'+(num%n-10));
    }else{
        s=(char)(num%n+'0');
    }
    s+=tmp;
    return s;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    string result = "";
    int cnt = 0;
    for(int i = 0 ;i <= t*m ;) {
        result+=invertStr(cnt,n);
        cnt++;
        i=result.size();
    }
    for(int i=p-1;i<t*m;i+=m){
        answer+=result[i];
    }
    return answer;
}