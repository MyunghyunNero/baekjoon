#include <iostream>
#include <string>
using namespace std;
char vowel[5]={'a','e','i','o','u'};
bool checkWord(char c){
    for(int i=0;i<5;i++){
        if(vowel[i]==c){
            return true;
        }
    }
    return false;
}
int main(){
    while(1){
        string s;
        cin>>s;
        if(s=="end") return 0;
        bool check=true;
        int acnt=0;//모음 갯수
        int bcnt=0;//자음 갯수
        int asequence=0; //모음 연속
        int bsequence=0; //자음 연속
        char before=s[0];
        if(checkWord(s[0])){
            acnt++;
            asequence++;
        }else{
            bcnt++;
            bsequence++;
        }
        for(int i=1;i<s.size();i++){
            if(before==s[i] && before !='e' && before !='o') {  //같은 숫자 연속
                check=false;
                break;
            }
            if(checkWord(s[i])){
                asequence++;
                acnt++;
                bsequence=0;
            }else{
                bsequence++;
                bcnt++;
                asequence=0;
            }
            if(asequence>=3||bsequence>=3){
                check=false;
                break;
            }
            before=s[i];
        }
        if(acnt==0){
            check=false;
        }
        if(check){
            cout<<'<'<<s<<'>'<<" "<<"is acceptable."<<'\n';
        }else{
            cout<<'<'<<s<<'>'<<" "<<"is not acceptable."<<'\n';
        }
    }
}