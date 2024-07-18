#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool correctStr(string str) {
    stack<char> stk;
    for(char c : str) {
        if(stk.empty()) {
            stk.push(c);
        }else {
            if(c==')' && stk.top()=='(') {
                stk.pop();
            }else {
                stk.push(c);
            } 
        }
    }
    return stk.empty();
}

bool balanceStr(string str) {
    int left = 0;
    int right = 0;
    for(char c : str) {
        if(c=='(') {
            left++;
        }
        if(c==')') {
            right++;
        }
    }
    return left == right;
}

string recur(string s) {
    if(correctStr(s)) return s;
    string u = "";
    string v = "";
    for(int i = 0;i<s.size(); i++) {
        u+=s[i];
        if(balanceStr(u)) {
            v = s.substr(i+1,s.size()-(i+1));
            break;
        }
    }
    if(correctStr(u)) {
        u+=recur(v);
    }else {
        string tmp = "";
        tmp += '(';
        tmp += recur(v);
        tmp += ')';
        string uTmp = "";
        for(int i =1;i<u.size()-1;i++) {
            if(u[i]=='(') uTmp+=')';
            if(u[i]==')') uTmp+='(';
        }
        u=tmp+uTmp;
    }
    return u;
}
string solution(string p) {
    string answer = recur(p);
    return answer;
}