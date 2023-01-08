#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    string ans;
    getline(cin,ans);
    int len=s.size();
    int ansLen =ans.size();
    int cnt=0;
    for(int i=0;i<len;i++){
        if(s.find(ans)!=string::npos){
            cnt++;
            s=s.substr(s.find(ans)+ansLen);
        }
    }
    cout<<cnt;
}