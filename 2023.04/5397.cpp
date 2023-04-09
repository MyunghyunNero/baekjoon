#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
int t;
int main(){
    while(t--){
        string s;
        string ans;
        cin>>s;
        int len = s.size();
        stack<char> left;
        stack<char> right;
        for(int i=0;i<len;i++){
            if(s[i]=='<'){
                if(!left.empty()){
                    char c= left.top();
                    left.pop();
                    right.push(c);
                }
            }else if(s[i]=='>'){
                if(!right.empty()){
                    char c= right.top();
                    right.pop();
                    left.push(c);
                }
            }else if(s[i]=='-'){
                if(!left.empty()) left.pop();
            }else{
                left.push(s[i]);
            }
        }
        while(!left.empty()){
            ans+=left.top();
            left.pop();
        }
        reverse(ans.begin(),ans.end());
        while(!right.empty()){
            ans+=right.top();
            right.pop();
        }
        cout<<ans;
    }
}