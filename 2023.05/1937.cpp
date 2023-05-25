#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n;
int dp[501][501];
int arr[501][501];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int ans;
int dfs(int a,int b){
    if(dp[a][b]!=0) return dp[a][b];
    dp[a][b]=1;
    for(int i=0;i<4;i++){
        int nx=a+dx[i];
        int ny=b+dy[i];
        if(nx<0 || nx>=n ||ny<0 ||ny>=n) continue;
        if(arr[a][b]<arr[nx][ny]){
            dp[a][b]=max(dp[a][b],dfs(nx,ny)+1);
        }
    }
    return dp[a][b];
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans=max(ans,dfs(i,j));
        }
    }
    cout<<ans;

}   