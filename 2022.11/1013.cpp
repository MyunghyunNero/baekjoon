#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(regex_match(s,regex("(100+1+|01)+"))) cout << "YES"<<'\n';
        else cout << "NO"<<"\n";
    }
}