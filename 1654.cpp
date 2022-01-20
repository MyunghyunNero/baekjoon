#include <iostream>
#include <vector>
using namespace std;
long long k,n;
bool check(vector<int>& v,long long x){           //x이 값이 n보다 작은지 아닌지 판단 
    long long cnt=0;
    for(int i=0;i<k;i++){
        cnt+=(v[i]/x);
    }
    return cnt>=n; 
int main(){
    cin>>k>>n;
    long long max=0;
    vector<long long> v(k);
    for(int i=0;i<k;i++){
        cin >> v[i];
        if(max<v[i]){
            max=v[i];
        }
    }
    long long ans=0;
    long long left=1;
    long long right=max;
    while(left<=right){                       //랜선 길이 구하기 위한 이분탐색
        long long mid=(left+right)/2;
        if(check(v,mid)){                    //mid값이 n보다 작지 않으면 길이 최대값 구하기위해 left를 mid+1지정
            if(ans<mid){
                ans=mid;
            }
            left=mid+1;
        }
        else{                               //mid값이 n보다 작으면 n보다 커져야하기 때문에 right=mid-1지정
            right=mid-1;
        }
    }
    cout <<ans;

}