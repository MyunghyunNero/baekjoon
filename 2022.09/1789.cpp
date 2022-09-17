#include <iostream>
using namespace std;
int main(){
    long long n;
    cin>>n;
    int num=1;
    long long sum=0;
    int cnt=0;
    while(1){
        sum+=num;
        if(n<sum){
            break;
        }
        num++;
        cnt++;
    }
    cout<<cnt;
}