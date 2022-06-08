#include <iostream>
#include <set>
#include <string>
using namespace std;
int main(){
    string s;
    set<string> ans;
    cin>>s;
    string sub;
    int len=s.length();
    for(int i=0;i<len;i++){
        for(int k=i;k<len;k++){
            sub+=s[k];
            ans.insert(sub);
        }
        sub="";
    }
    cout << ans.size();
}