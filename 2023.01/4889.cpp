#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(){
    int index =1;
    while(1){
        string s;
        cin>>s;
        if(s.find("-")!=-1){
            break;
        }
        int cnt=0;
        stack<char> stk;
        int len=s.size()-1;
        for(int i=0;i<=len;i++){
            if(stk.empty() && s[i]=='}'){
                cnt++;
                stk.push('{');
            }else if(!stk.empty() && s[i]=='}'){
                stk.pop();
            }else{
                stk.push('{');
            }
        }
        cnt += stk.size()/2;
        cout<< index << '.'<<" "<< cnt<<'\n';
        index++;
    }
}
