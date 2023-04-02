#include <iostream>
using namespace std;
long long gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int main(){
    int x,y;
    cin>>x>>y;
    cout<<x+y-gcd(x,y);
}