#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main(){
    int n;
    cin>>n;
    string reg;
    cin>>reg;
    int idx = reg.find("*");
    string s_before = reg.substr(0, idx);
    string s_after = reg.substr(idx + 1);
    string new_pattern = s_before + "[a-z]*" + s_after;
    regex rgx(new_pattern);
    while(n--){
        string s;
        cin>>s;
        if(regex_match(s,rgx)){
            cout<<"DA"<<'\n';
        }else{
            cout<<"NE"<<'\n';
        }
    }
}