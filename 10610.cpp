#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    int sum=0;
    for(char c:s){
        sum+=c-'0';
    }
    sort(s.begin(),s.end());
    if(s[0]=='0'&& sum%3==0){           //30의 배수는 각 자리의 수의 합이 3의 배수이고 마지막 숫자는 0이어야한다
        reverse(s.begin(),s.end());     // 30=2*3*5 이기 때문
        cout << s;
    }
    else{
        cout <<-1;
    }
}