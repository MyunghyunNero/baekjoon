#include <iostream>
using namespace std;
int main(){
    int n,x,a,b;
    int sum=0;
    cin>>x>>n;
    while(n--){
        cin>>a>>b;
        sum+=(a*b);
    }
    if(x==sum){
        cout <<"Yes";
    }else{
        cout <<"No";
    }
}