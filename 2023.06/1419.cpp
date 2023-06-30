#include <iostream>
using namespace std;
int l,r,k;
int main(){
    cin>>l>>r>>k;
    int cnt=0;;
    if(k==2){
        if(l>2){
            cnt=r-l+1;
        }else{
            cnt=r-2;
        }
        cout<<cnt;
    }
    if(k==3){
        for(int i=l;i<=r;i++){
            if((i%3==0)&& (i>=6)){
                cnt++;
            }
        }
        cout<<cnt;
    }
    if(k==4){
        for(int i=l;i<=r;i++){
            if(i>=10){
                if(((i%2)==0)&&(i!=12)){
                    cnt++;
                }
            }
        }
        cout<<cnt;
    }
    if(k==5){
        for(int i=l;i<=r;i++){
            if(i>=15){
                if(i%5==0){
                    cnt++;
                }
            }
        }
        cout<<cnt;
    }
}