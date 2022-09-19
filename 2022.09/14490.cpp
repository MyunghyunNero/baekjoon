#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n,m;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int main(){
    string s;
    cin>>s;
    bool checkpoint=false;
    int d=1;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]==':'){
            checkpoint=true;
            d=1;
            continue;
        }
        if(checkpoint){
            n+=(s[i]-'0')*d;
            d*=10;
        }else{
            m+=(s[i]-'0')*d;
            d*=10;
        }
    }
    int g=gcd(n,m);
    cout<<n/g<<':'<<m/g;
    return 0;
}
