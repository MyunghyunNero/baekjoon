#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int value;
long long sum;
int ans;
vector<int> v;
void binary(int left,int right){
    while(left<=right){
        sum=0;
        int mid=(left+right)/2;
        for(int i=0;i<n;i++){
            if(v[i]>mid) {
                sum+=mid;
            }else{
                sum+=v[i];
            }
        }
        if(sum<=value){
            ans=mid;
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
        sum+=a;
    }
    sort(v.begin(),v.end());
    cin>>value;
    int maxv=v[n-1];
    binary(0,maxv);

    cout<<ans;
}