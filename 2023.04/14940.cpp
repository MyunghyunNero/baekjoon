#include <iostream>
#include <queue>
using namespace std;
int n,m;
int arr[1001][1001];
int ans[1001][1001];
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};
void bfs(int sx,int sy){
    queue<pair<pair<int,int>,int>> q;
    q.push({{sx,sy},0});
    ans[sx][sy]=0;
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int d=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            int nd=d+1;
            if(arr[nx][ny]==0 || arr[nx][ny]==2 || ans[nx][ny]!=0) continue;
            q.push({{nx,ny},nd});
            ans[nx][ny]=nd;
        }
    }
}
int main(){
    cin>>n>>m;
    int startx,starty;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]==2){
                startx=i;
                starty=j;
            }
        }
    }   
    bfs(startx,starty);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1 && ans[i][j]==0){
                ans[i][j]=-1;
            }
        }   
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<' ';
        }   
        cout<<'\n';
    }
    
}