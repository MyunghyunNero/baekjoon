#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='P'){
            for(int j=-k;j<=k;j++){
                if(i+j>=0&&i+j<n){
                    if(s[i+j]=='H'){
                        s[i+j]='X';
                        cnt++;
                        break;
                    }
                }
            }
        }
    }
    cout<<cnt;
}