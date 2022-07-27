#include <iostream>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m,cnt;
int dp[501][501];
int arr[501][501];
int dfs(int x,int y){
    if(x==n-1&&y==m-1){
        return 1;
    }
    if(dp[x][y]!=-1){
        return dp[x][y];
    }
    dp[x][y]=0;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&ny>=0&&nx<n&&ny<m){
            if(arr[nx][ny]<arr[x][y]){
                dp[x][y]=dp[x][y]+dfs(nx,ny);             //다이나믹프로그래밍 경로의 수를 더해가서 처음 시작한 위치까지 돌아감
            }   
        }
    }
    return dp[x][y];
}
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
            cin>>arr[i][k];
            dp[i][k]=-1;
        }
    }
    cnt=dfs(0,0);
    cout<<cnt;
}