#include <iostream>
#include <vector>
using namespace std;
int n,m;
bool check(vector<long long>& v,int x){
    long long cnt=0;
    for(int i=0;i<n;i++){
        long long temp= v[i]-x;
        if(temp>=0){
            cnt+=temp;
        }
    }
    return cnt>=m;
}
int main(){
    cin >>n>>m;
    vector<long long> v(n);
    long long max=0;
    for(int i=0;i<n;i++){
        cin >>v[i];
        if(max<v[i]){
            max=v[i];
        }
    }
    long long left=0;
    long long right=max;
    long long ans=0;
    while(left<=right){
        long long mid=(left+right)/2;
        int ok=check(v,mid);
        if(ok){
            left=mid+1;
            if(ans<mid){
                ans=mid;
            }
        }
        else{
            right=mid-1;
        }
    }
    cout << ans;

}