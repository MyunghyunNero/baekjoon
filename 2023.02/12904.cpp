#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s,t;
void one(){
    t.pop_back();
}
void two(){
    t.pop_back();
    reverse(t.begin(),t.end());
}
int main(){
    cin>>s>>t;
    bool check =false;
    int sLen=s.size();
    int tLen=t.size();
    for(int i=0;i<tLen-sLen;i++){
        if(t.back()=='A'){
            one();
        }else if(t.back()=='B'){
            two();
        }
    }
    if(s==t){
        cout<<1;
    }else{
        cout<<0;
    }
}