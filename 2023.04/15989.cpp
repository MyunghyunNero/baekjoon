#include <iostream>
using namespace std;
int d[10001];
int n;
int main(){
    d[1]=1;
    d[2]=2;
    d[3]=3;
    cin>>n;
    for(int i=4;i<=10000;i++){
        d[i]=d[i-3]+i/2+1;
    }
    while(n--){
        int a;
        cin>>a;
        cout<<d[a]<<'\n';
    }
}