#include <iostream>
using namespace std;
long long a,b;
long long cal(long long n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }else if(n%2==1){
        return n/2+2*cal(n/2)+1;
    }else if(n%2==0){
        return n/2+2*cal(n/2);
    }
}
int main(){
    cin >> a>>b;
    cout<<cal(b)-cal(a-1);
}