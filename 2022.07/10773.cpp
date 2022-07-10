#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> s;
    int n;
    int ans=0;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        if(a==0){
            s.pop();
        }else{
            s.push(a);
        }   
    }
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
    cout<<ans;
}