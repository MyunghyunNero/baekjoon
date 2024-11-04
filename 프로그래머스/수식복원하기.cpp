#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
bool check[10];
vector<string> answerExpression;
int change(int num, int ch) {
    int sum = 0;
    int idx = 0;
    while(num) {
        if(idx ==0){
            sum +=num%10;
        }else {
            sum +=((num%10) * ch);
            ch*=ch;
        }
        num/=10;
        idx++;
    }
    return sum;
}
string changeStr(int num,int ch) {
    string ret = "";
    if(num==0) {
        return "0";
    }
    while(num) {
        ret+=(num%ch)+'0';
        num/=ch;
    }
    
    reverse(ret.begin(),ret.end());
    return ret;
    
}
bool checkNum(string str,int ch) {
    int firstNum;
    int secondNum;
    int ansNum;
    string tmp="";
    int idx = 0;
    char exp;
    for(char c : str) {
        if(c==' ') continue;
        if(c=='+' || c=='-') {
            firstNum = stoi(tmp);
            tmp="";
            exp = c;
            continue;
        }else if(c=='='){
            secondNum = stoi(tmp);
            tmp = "";
            continue;
        }
        if(c-'0'>=ch) {
            return false;
        }
        tmp+=c;
    }
    ansNum = stoi(tmp);
    if(exp =='+') {
        if(change(firstNum,ch) + change(secondNum,ch) == change(ansNum,ch)){
            return true;
        }else{
            return false;
        }
    }else {
        if(change(firstNum,ch) - change(secondNum,ch) == change(ansNum,ch)){
            return true;
        }else{
            return false;
        }
    }
    
}
string checkStr(string str,int ch) {
    int firstNum;
    int secondNum;
    int ansNum;
    string ret = "";
    for(char c : str) {
        ret +=c;
        if(c=='=') {
            ret+=" ";
            break;
        }
    }
    string tmp="";
    int idx = 0;
    char exp;
    for(char c : str) {
        if(c==' ') continue;
        if(c=='+' || c=='-') {
            firstNum = stoi(tmp);
            tmp="";
            exp=c;
            continue;
        }else if(c=='='){
            secondNum = stoi(tmp);
            tmp = "";
            continue;
        }
        tmp+=c;
    }
    int num=0;
    if(exp == '+'){
        num = change(firstNum,ch) + change(secondNum,ch);
    }else{
        num = change(firstNum,ch) - change(secondNum,ch);
    }
    if(tmp == "X") {
        ret += changeStr(num,ch);
    }else {
        if(tmp != changeStr(num,ch)){
            ret += '?';
        }else{
            ret += tmp;
        }
        
    }
    return ret;
}
vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    for(int i=2;i<=9;i++) {
        check[i] = true;
    }
    for(string expression : expressions) {
        for(char c : expression) {
            if(c>='0' && c<='9') {
                for(int i=2;i<=9;i++) {
                    if(check[i] && i<=c-'0') {
                        check[i] = false;
                    }
                }
            }
        }
    }
    for(string expression : expressions) {
        if(expression.find("X")!=string::npos) {
            answerExpression.push_back(expression);
        }else{
            for(int i=2;i<=9;i++) {
                if(!checkNum(expression,i)) {
                    check[i] = false;
                }
            }
        }
        
    }
    for(int i=0;i<answerExpression.size();i++) {
        for(int j=2;j<=9;j++) {
            if(check[j]) {
                answerExpression[i]= checkStr(answerExpression[i],j);
            }
        }
        
    }
    return answerExpression;
}