#include <iostream>
#include <stack>
using namespace std;
int n;
vector<int> v;
int cnt=1;
stack<int> s[4];
int main(){
    cin>>n;
    bool check=true;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        bool check1=false;
        for(int j=0;j<4;j++){
            if(s[j].empty() || s[j].top()<a){
                s[j].push(a);
                check1=true;
                break;
            }
        }
        if(!check1) check=false;
    }
    if(check){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}