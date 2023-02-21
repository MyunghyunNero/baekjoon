#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    queue<int> q;
    while(n--){
        string s;
        cin>>s;
        if(s=="push"){
            int a;
            cin>>a;
            q.push(a);
        }else if(s=="pop"){
            if(q.empty()){
                cout<<-1<<'\n';
            }else{
                int a=q.front();
                q.pop();
                cout<<a<<'\n';
            }
        }else if(s=="size"){
            cout<<q.size()<<'\n';
        }else if(s=="empty"){
            if(q.empty()){
                cout<<1<<'\n';
            }else{
                cout<<0<<'\n';
            }
        }else if(s=="front"){
            if(q.empty()){
                cout<<-1<<'\n';
            }else{
                cout<<q.front()<<'\n';
            }
        }else{
            if(q.empty()){
                cout<<-1<<'\n';
            }else{
                cout<<q.back()<<'\n';
            }
        }
    }
}