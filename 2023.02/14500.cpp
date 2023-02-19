#include <iostream>
#include <cstring>
using namespace std;
int arr[501][501];
bool check[501][501];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m,ans;
void dfs(int x,int y,int cnt,int value){
    if(cnt==4){
        if(ans<value){
            ans=value;
        }
        return;
    }

    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0 || ny<0 ||nx>=n ||ny>=m || check[nx][ny]) continue;
        check[nx][ny]=true;
        dfs(nx,ny,cnt+1,value+arr[nx][ny]);
        check[nx][ny]=false;
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            check[i][j]=true;
            dfs(i,j,1,arr[i][j]);
            check[i][j]=false;
            if(i-1 >= 0 && j-1 >= 0 && i+1 < n) { //ㅓ
                ans = max(ans, (arr[i-1][j] + arr[i][j-1] + arr[i][j] + arr[i+1][j]));
            }
            if(i-1 >= 0 && j+1 <m && i+1 < n) { //ㅏ
                ans = max(ans, (arr[i-1][j] + arr[i][j+1] + arr[i][j] + arr[i+1][j]));
            }
            if(j-1 >= 0 && i-1 >=0 && j+1 <m) { //ㅗ
                ans = max(ans, (arr[i][j] + arr[i-1][j] + arr[i][j-1] + arr[i][j+1]));
            }
            if(j-1 >= 0 && j+1 < m && i+1 < n) { //ㅜ
                ans = max(ans, (arr[i][j-1] + arr[i][j] + arr[i][j+1] + arr[i+1][j]));
            }
        }
    }
    cout<<ans;
}