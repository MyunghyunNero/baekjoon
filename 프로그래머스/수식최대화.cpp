#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
vector<long long> num;
vector<char> oper;
string str;
vector<char> v;
int priority(char c){
    if(v[0]==c){
        return 2;
    }else if(v[1]==c){
        return 1;
    }else{
        return 0;
    }
}
long long opernum(long long num1,long long num2,char ch){
    if(ch=='-'){
        return num1-num2;
    }else if(ch=='+'){
        return num1+num2;
    }else{
        return num1*num2;
    }
}
long long operStr(){
    stack<long long> number;
    stack<char> op;
    for(int i=0;i<oper.size();i++){
        number.push(num[i]);
        if(op.empty()){
            op.push(oper[i]);
        }else{
            while(!op.empty()&&priority(oper[i])<=priority(op.top())){
                long long num1=number.top();
                number.pop();
                long long num2=number.top();
                number.pop();
                char ch=op.top();
                op.pop();
                long long res=opernum(num2,num1,ch);
                
                number.push(res);
            }
            op.push(oper[i]);
        }
    }
    number.push(num[num.size()-1]);
    while(!op.empty()){
        long long num1=number.top();
        number.pop();
        long long num2=number.top();
        number.pop();
        char ch=op.top();
        op.pop();
        long long res = opernum(num2,num1,ch);
        number.push(res);
    }
    return number.top();
}

long long solution(string expression) {
    long long answer = 0;
    for(int i=0;i<expression.size();i++){
        if(expression[i]!='+' && expression[i]!='-' && expression[i]!='*'){
            str+=expression[i];
        }else{
            num.push_back(stol(str));
            oper.push_back(expression[i]);
            str="";
        }
    }
    num.push_back(stol(str));
    v={'+','-','*'};
    answer=max(answer,abs(operStr()));
    v={'+','*','-'};
    answer=max(answer,abs(operStr()));
    v={'-','*','+'};
    answer=max(answer,abs(operStr()));
    v={'-','+','*'};
    answer=max(answer,abs(operStr()));
    v={'*','+','-'};
    answer=max(answer,abs(operStr()));
    v={'*','-','+'};
    answer=max(answer,abs(operStr()));
    return answer;
}