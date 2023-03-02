#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int arr[102][102];
int n,m;
int dist[101][101];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void bfs(){
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=m||ny<0||ny>=n) continue;
            if(arr[nx][ny]==1){
                if(dist[nx][ny]>dist[x][y]+1){
                    dist[nx][ny]=dist[x][y]+1;
                    q.push({nx,ny});
                }
            }else{
                if(dist[nx][ny]>dist[x][y]){
                    dist[nx][ny]=dist[x][y];
                    q.push({nx,ny});
                }
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            arr[i][j]=s[j]-'0';
            dist[i][j]=987654321;
        }
    }
    dist[0][0]=0;
    bfs();
    cout<< dist[m-1][n-1];
}  