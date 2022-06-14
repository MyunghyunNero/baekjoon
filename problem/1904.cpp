#include <iostream>
using namespace std;
int d[1000001];

int fibonacci(int n){
    if(d[n]!=0){
        return d[n];
    }
    if(n<=1){                     //1일 떄는 타일 갯수 1  
        d[1]=1;
        return d[1];
    }
    if(n==2){                 //2일떄는 타일 갯수 2
        d[2]=2;
        return d[2];
    }
    d[n]=(fibonacci(n-1)+fibonacci(n-2))%15746;      //피보나치 수열이랑 똑같음
    return d[n];
}
int main(){
    int t;
    cin>> t;
    int ans = fibonacci(t)%15746;
    cout <<ans;
}