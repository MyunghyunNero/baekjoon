#include <iostream>
using namespace std;
int cnt;
int n,m;
int main(){
    cin>>n>>m;                               //N=x+(x+1)+ ... (x+L-1) L은 길이 
    int lx,x=-1,cnt=-1;                       //N= Lx+(L-1)*L/2 인것을 이용
    for(int i=m;i<=100;i++){
        lx=(i-1)*i/2;
        if((n-lx)%i==0&&(n-lx)/i>=0){
            x=(n-lx)/i;
            cnt=i;
            break;
        }
    }
    if(x==-1){
        cout <<-1;
    }else{
        for(int i=0;i<cnt;i++){
            cout << x+i<<' ';
        }
    }
}