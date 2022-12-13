#include <iostream>
using namespace std;
int arr[1001];
int n,k;
int main(){
    int cnt=0;
    int ans;
    cin>>n>>k;
    for(int i=2;i<=n;i++){
        if(arr[i]==1) continue;
        for(int j=i;j<=n;j+=i){
        	if(arr[j]==1) continue;
            if(cnt==k){
                break;
            }
            arr[j]=1;
            cnt++;
            ans=j;
        }
    }
    cout<<ans;
}