#include <iostream>
#include <string>
#include <stack>
using namespace std;
string s;
stack<char> stk;
int main(){
    cin>>s;
    int len = s.size();
    int cnt = 0;
    bool check = true;
    for(int i=0;i<len;i++){
        if(!stk.empty() && stk.top()=='A' && s[i]=='P'){
            stk.pop();
           
            if(!stk.empty() &&stk.top()=='P'){
                stk.pop();
            }else{
            	check=false;
            	break;
            }
            if(stk.empty()) {
            	check=false;
            	break;
            }
            if(stk.top()!='P'){
            	check=false;
            	break;
            }
        }else{
            stk.push(s[i]);
        }
    }
    
    if(stk.size()==1 && stk.top()=='P'){
    }else{
    	check=false;
    }
    if(check){
        cout<<"PPAP";
    }else{
        cout<<"NP";
    }
    
}   