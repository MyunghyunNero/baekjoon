#include <iostream>
using namespace std;
long long a,b,c;
long long square(int a,int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return a;
    }
    if(n%2==1){
        return square(a,n-1)*a;
    }
    long long half=square(a,n/2);
    half%=c;
    return half*half%c; 
}
int main(){
    cin>>a>>b>>c;
    cout << square(a,b)%c;
}