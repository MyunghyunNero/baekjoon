#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long n,k,mid,cnt;
vector<long long> b;
int main(){
    cin>>n;
    cin>>k;
    long long low=1;
    long long high=n*n;
    while(low<=high){
        mid=(low+high)/2;
        cnt=0;
        for(int i=1;i<=n;i++){
            cnt+=min(mid/i,n);
        }
        if(cnt>=k){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<low;
}