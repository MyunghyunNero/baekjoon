#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool arr[1000001];
bool checkprime(long long n){
    if(n==1) return false;
    for(long long i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int change(int num,int k){
    long long s=0;
    vector<long long> v;
    long long idx=1;
    while(num){
        long long remain=num%k;
        num/=k;
        if(remain){
            s+=remain*idx;
            idx*=10;
        }else if(s!=0){
            v.push_back(s);
            s=0;
            idx=1;
        }else{
            s=0;
            idx=1;
        }
    }
    if(s!=0){
        v.push_back(s);
    }
    int cnt=0;
    for(int i=0;i<v.size();i++){
        if(checkprime(v[i])) { cout<<v[i] <<' ';cnt++;}
    }
    return cnt;
}
int solution(int n, int k) {
    
    return change(n,k);
}