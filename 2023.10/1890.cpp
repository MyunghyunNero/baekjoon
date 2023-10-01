#include <iostream>
#include <queue>
using namespace std;
int arr[101][101];
long long ans[101][101];
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    ans[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==0) continue;
            if(i+arr[i][j]<n){
                ans[i+arr[i][j]][j]+=ans[i][j];
            }
            if(j+arr[i][j]<n){
                ans[i][j+arr[i][j]]+=ans[i][j];
            }
        }
    }
    cout<<ans[n-1][n-1];
}