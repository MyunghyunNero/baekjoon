#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<int> num;           // 숫자 저장
    vector<char> sign;        //부호 저장
    int number=0;
    sign.push_back(1);
    for(int i=0;i<s.size();i++){
        if(s[i]=='-' || s[i]=='+'){       //부호일경우 저장
            if(s[i]=='-'){
                sign.push_back(-1);
            }
            if(s[i]=='+'){
                sign.push_back(1);
            }
            num.push_back(number);
            number=0;
        }
        else{
            number=number*10+(s[i]-'0');       //문자열을 숫자로 치환
        }
    }
    num.push_back(number);
    bool minus=false;
    int sum=0;
    for(int i=0;i<num.size();i++){
        if(sign[i]==-1){          //-가 나오면 쭉 뺴면 됨
            minus=true;
        }
        if(minus==false){
            sum+=num[i];
        }
        if(minus==true){
            sum-=num[i];
        }
    }
    cout<<sum;

}