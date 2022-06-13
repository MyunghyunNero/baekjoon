#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a[3];
    for(int i=0;i<3;i++){
        cin >>a[i];
    }
    sort(a,a+3);
    int cnt=0;
    int ans=0;
    for(int i=0;i<3;i++){
        for(int k=i+1;k<3;k++){
            if(a[i]==a[k]){
                cnt++;
                ans=a[i];
            }
        }
    }
    if(cnt==3){
        cout <<10000+ans*1000;
    }
    else if(cnt==1){
        cout<<1000+ans*100;
    }else{
        cout<<a[2]*100;
    }

}