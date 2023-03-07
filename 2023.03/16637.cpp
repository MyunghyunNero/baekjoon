#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int n;
string s;
int sum=-987654321;
int cal(int a,int b,char op){
    int res=a;
    switch (op)
    {
    case '+' : res+=b; break;
    case '-' : res-=b; break;
    case '*' : res*=b; break;
    }
    return res;
}
void dfs(int idx,int cur){
    if(idx>=n){
        sum=max(sum,cur);
        return;
    }
    char op=(idx==0)? '+' : s[idx-1];

    if(idx+2<n){
        int bracket=cal(s[idx]-'0',s[idx+2]-'0',s[idx+1]);
        dfs(idx+4,cal(cur,bracket,op));
    }

    dfs(idx+2,cal(cur,s[idx]-'0',op));
}
int main(){
    cin>>n;
    cin>>s;
    dfs(0,0);
    cout<<sum;
} 