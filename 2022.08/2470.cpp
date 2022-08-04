#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long n;
vector<long long> v;
long long z=9000000000;
long long sans;
long long lans;
int main(){
    cin >>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int start=0;
    int end=n-1;
    while(start<end){
        if(abs(z)>=abs(v[start]+v[end])){
            z=(v[start]+v[end]);
            sans=v[start];
            lans=v[end];
            if(z==0){
                break;
            }
        }
        if(v[start]>=0){
            end--;
        }else if(v[end]<0){
            start++;
        }else{
            if(abs(v[start])>=abs(v[end])){
                start++;
            }else{
                end--;
            }
        }
    }
    cout <<sans<<' '<<lans;
}