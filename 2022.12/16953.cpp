#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int cnt=0;
    bool check=false;
    while(b!=0){
        if(b==a){
            check=true;
            break;
        }
        if(b%10==1) {
            b/=10;
            cnt++;
        }else if(b%2==0){
            b/=2;
            cnt++;
        }else{
            break;
        }
    }

    if(check){
        cout<<cnt+1;
    }else{
        cout << -1;
    }
}