#include <iostream>
using namespace std;
long long c=1000000007;
long long square(long long x,long long n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return x;
    }
    if(n%2==1){
        return square(x,n-1)*x%c;
    }
    long long half=square(x,n/2);
    half%=c;
    return half*half%c; 
}
int main(){
    int n,k;
    cin>>n>>k;
    long long a=1,b=1;
    for(int i=n;i>=n-k+1;i--){
        a=(a*i)%c;
    }
    for(int i=2;i<=k;i++){
        b=(b*i)%c;
    }
    cout << (a*square(b,c-2))%c;       //페르소의 소정리        a^(p-1)=1(mod p)  -> a^(p-2)=a^-1(mod p)
}