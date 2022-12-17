#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<char> s;
int ans;
int main(){
    string str;
    cin>>str;
    int len= str.size();
    int sum=1;
    for(int i=0;i<len;i++){
        if(str[i]=='('){
            s.push(str[i]);
            sum*=2;
        }
        else if(str[i]=='['){
            s.push(str[i]);
            sum*=3;
        }
        else if(str[i]==')'){
            if(s.empty() || s.top()!='('){
                ans=0;
                break;
            }
            if(str[i-1]=='('){
                ans+=sum;
                sum/=2;
                s.pop();
            }else{
                sum/=2;
                s.pop();
            }
        }
        else if(str[i]==']'){
            if(s.empty() || s.top()!='['){
                ans=0;
                break;
            }
            if(str[i-1]=='['){
                ans+=sum;
                sum/=3;
                s.pop();
            }else{
                sum/=3;
                s.pop();
            }
        }
    }
    if(!s.empty()) ans=0;
    cout<<ans;
}