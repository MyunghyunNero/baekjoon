#include <iostream>
using namespace std;
int n;
int arr[12];
int ans[12];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(ans[j]!=0){
                continue;
            }
            if(cnt==arr[i]){
                ans[j]=i;
                break;
            }
            
            if(ans[j]==0){
                cnt++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }

}