#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int aLen=a.size();
    int bLen = b.size();
    if(aLen>bLen){
        for(int i=0;i<aLen-bLen;i++){
            b+='0';
        }
    }else{
        for(int i=0;i<bLen-aLen;i++){
            a+='0';
        }
    }
    int maxLen=max(aLen,bLen);
    int carry=0;
    string ans="";
    for(int i=0;i<maxLen;i++){
        int sum = (a[i]-'0')+(b[i]-'0') + carry;
        ans+=sum%10+'0';
        carry=sum/10;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    

}