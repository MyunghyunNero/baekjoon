#include <iostream>
#include <stack>
using namespace std;
int n;
stack<int> s;
int pre=0;
int ans;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        while(!s.empty() && s.top()>b){
            ans++;
            s.pop();
        }
        s.push(b);
    }
    while(!s.empty()&& s.top()>0){
        ans++;
        s.pop();
    }

    cout<<ans;
}