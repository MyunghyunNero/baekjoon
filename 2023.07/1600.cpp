#include <iostream>
#include <queue>
using namespace std;
int K,w,h;
int arr[201][201];
int dp[201][201][31];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int horx[]={2,1,-2,1,2,-1,-2,-1};
int hory[]={1,2,1,-2,-1,2,-1,-2};
int ans=987654321;
void bfs(){
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{0,0},{0,0}});
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int cnt=q.front().second.first;
        int k=q.front().second.second;
        q.pop();
        if(x==h-1 && y==w-1){
            ans=cnt;
            return;
        }
        if(k<K){
            for(int i=0;i<8;i++){
                int nx=x+horx[i];
                int ny=y+hory[i];
                if(nx<0 || nx>=h || ny<0 || ny>=w ) continue;
                if(arr[nx][ny]==1) continue;
                if(dp[nx][ny][k+1]==-1){
                    dp[nx][ny][k+1]=cnt+1;
                    q.push({{nx,ny},{cnt+1,k+1}});
                }
            }
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || nx>=h || ny<0 || ny>=w ) continue;
            if(arr[nx][ny]==1) continue;
            if(dp[nx][ny][k]==-1){
                dp[nx][ny][k]=cnt+1;
                q.push({{nx,ny},{cnt+1,k}});
            }
        }
    }
}
int main(){
    cin>>K>>w>>h;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<201;i++){
        for(int j=0;j<201;j++){
            for(int t=0;t<31;t++){
                dp[i][j][t]=-1;
            }
        }
    }
    bfs();
    if(ans==987654321){
        cout<<-1;
    }else{
        cout<<ans;
    }
}