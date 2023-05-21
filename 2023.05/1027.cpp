#include <iostream>
using namespace std;
int n;
int arr[51];
int cnt[51];
int ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        double maxGrad=-1000000000;
        for(int j=i+1;j<=n;j++){
            int h=arr[j]-arr[i];
            int w = j-i;
            double grad= (double)h/(double)w ;
            if(grad<=maxGrad) continue;
            maxGrad=grad;
            cnt[i]++;cnt[j]++;
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,cnt[i]);
    }
    cout<<ans;
}