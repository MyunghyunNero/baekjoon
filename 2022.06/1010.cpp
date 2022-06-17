#include <iostream>
using namespace std;
int arr[31][31];
int fibo(int n,int k){
    if(arr[n][k]!=0){
        return arr[n][k];
    }
    if(n==k|| k==0){
        arr[n][k]=1;
        return 1;
    }
    arr[n][k]=fibo(n-1,k-1)+fibo(n-1,k);
    return arr[n][k];
   
}
int main(){
    int a,b;
    int n;
    cin>>n;
    while(n--){
        cin>>b>>a;
        fibo(a,b);
        cout << arr[a][b]<<'\n';
    }
}