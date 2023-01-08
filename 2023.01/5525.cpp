#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int ans=0;
    for(int i = 1; i < s.size(); i++){
        int count = 0;
        if(s[i-1]=='I'){
            while(s[i]=='O' && s[i+1]=='I'){
                i+=2;
                count++;
                if(count == n ){ count--; ans++;}
            }
        }
    }
    cout << ans <<'\n';
}