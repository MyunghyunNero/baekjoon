#include <iostream>
#include <string>
using namespace std;
string s;
int len;
//팰린드롬 체크 함수
bool palin(int n){
    int half = (len - n )/2;
    for(int i=0;i<half;i++){
        if(s[i+n]!=s[len-1-i]) return false;
    }
    return true;
}
//앞에 한개씩 제거해주머 팰린드롬 체크   + 최초 펠린드롬이 곧 가장 짧은 펠린드롬
int main(){
    cin>>s;
    len=s.size();
    for(int i=0;i<len;i++){
        if(palin(i)){
            cout<<len+i;
            return 0;
        }
    }
}