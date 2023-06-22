#include <iostream>
#include <string>
using namespace std;
int n,k;
string s;
int main(){
    cin>>n>>k;
    int mx= n/2*(n-n/2);
    if(mx<k){
        cout<<-1;
    }else if(k==0){
    	for(int i = 0; i < n - 1; i++)
            cout << 'B';
        cout << 'A';
    }else{
        int cnt=1;
        for(int i=1;i<=n/2;i++){
            if(i*(n-i)>=k){
                cnt=i;
                break;
            }
        }
        for(int i=1;i<=cnt;i++){
            if(n-cnt<k){
                k=k-n+cnt;
                s+='A';
            }
            else{
                for(int j=0;j<n-i-k;j++){
                    s+='B';
                }
                s+='A';
                break;
            }
        }
        for(int i=0;i<k;i++){
            s+='B';
        }
        cout<<s;
    }
}