#include <iostream>
#include <string>
using namespace std;
string a,b;
int ans=99999999;
int main(){
    cin>>a>>b;
    for(int i=0;i<=b.length()-a.length();i++){
        int cnt=0;
        for(int k=0;k<a.length();k++){
            if(a[k]!=b[k+i]){
                cnt++;
            }
        }
        if(ans>cnt){
            ans=cnt;
        }
    }
    cout<<ans;
}