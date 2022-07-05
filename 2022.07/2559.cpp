#include <iostream>
using namespace std;
int arr[100001];
int sum[100001];
int ans=-99999999;
int n,k;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int a;
        cin>> a;
        arr[i]=a;
        sum[i]=sum[i-1]+a;
        if(i>k){
            sum[i]-=arr[i-k];
        }
    }
    for(int i=k;i<=n;i++){
        if(ans<sum[i]){
            ans=sum[i];
        }
    }
    cout<<ans;

}