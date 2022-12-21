#include <iostream>
#include <string>
using namespace std;
int ans=1;
string s;
int main(){
    cin>>s;
    int len = s.size();
    char c = s[0];
    for(int i=1;i<len;i++){
        if(c!=s[i]){
            c=s[i];
            ans++;
        }
    }
    cout<<ans/2;
}