#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        string ans;
        cin>>s;
        cin>>ans;
        int wb=0;
        int bw=0;
        for(int i=0;i<n;i++){
            if(s[i]!=ans[i] && s[i]=='W'){
                wb++;
            }
            if(s[i]!=ans[i] && s[i]=='B'){
                bw++;
            }
        }
        int flip=abs(wb-bw);
        int change = max(wb,bw) - flip ;
        
        cout<< change + flip << '\n' ;
    }
}