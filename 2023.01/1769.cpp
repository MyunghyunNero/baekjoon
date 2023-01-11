#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin>>s;
    int sum=0;
    int cnt=0;
    while(s.size()!=1){
        cnt++;
        for(int i=0;i<s.size();i++){
            sum+=(s[i]-'0');
        }
        s=to_string(sum);
        sum=0;
    }
    int ans = stoi(s);
    string res="";
    if(ans%3==0){
        res="YES";
    }else{
        res="NO";
    }
    cout<<cnt<<'\n'<<res;
    
}