#include <iostream>
using namespace std;
long long m,M;
bool check[1000002];
int main(){
    cin>>m>>M;
    int diff=M-m;
    for(long long i=2;i*i<=M;i++){
        long long n=m/(i*i);

        if(m%(i*i)) n++;
        while(n*i*i <=M){
            check[n*i*i-m]=true;
            n++;
        }
    }   
    int cnt=0;
    for(int i=0;i<=diff;i++){
        if(!check[i]) cnt++;
    }
    cout<<cnt;
}