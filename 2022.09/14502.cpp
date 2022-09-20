#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int arr[8][8];
int temp[8][8];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int n,m;
int ans;
void init(int (*a)[8],int (*b)[8]){
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            a[i][j] = b[i][j];
} 
void bfs(){
    int virus[8][8];
    init(virus,temp);
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(virus[i][j]==2){
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m){
                if(virus[nx][ny]==0){
                    virus[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(virus[i][j]==0){
                cnt++;
            }
        }
    }
    ans=max(ans,cnt);
}
void w(int cnt){
    if(cnt==3){
        bfs();
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(temp[i][j]==0){
                temp[i][j]=1;
                w(cnt+1);
                temp[i][j]=0;
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            temp[i][j]=arr[i][j];
        }
    }
    w(0);
    cout<<ans;

}