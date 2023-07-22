#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int rsize;
int csize;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<string> arr;
bool visited[101][101];
int bfs(int r,int c,int destination){
    queue<pair<pair<int,int>,int>> q;
    visited[r][c]=true;
    q.push({{r,c},0});
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int cnt=q.front().second;
        q.pop();
        if(destination==1 && arr[x][y]=='L'){
            return cnt;
        }
        if(destination==2 && arr[x][y]=='E'){
            return cnt;
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=rsize || nx<0 || ny >=csize || ny<0) continue;
            if(arr[nx][ny]=='X') continue;
            if(!visited[nx][ny]){
                q.push({{nx,ny},cnt+1});
                visited[nx][ny]=true;
            }
        }
    }
    return -1;
}
int solution(vector<string> maps) {
    int answer = 0;
    arr=maps;
    rsize= maps.size();
    csize=maps[0].size();
    int startx;
    int starty;
    int reverx;
    int revery;
    for(int i=0;i<rsize;i++){
        for(int j=0;j<csize;j++){
            if(arr[i][j]=='S'){
                startx=i;
                starty=j;
            }
            if(arr[i][j]=='L'){
                reverx=i;
                revery=j;
            }
        }
    }
    int rever= bfs(startx,starty,1);
    memset(visited,false,sizeof(visited));
    int exit=bfs(reverx,revery,2);
    if(rever==-1 || exit==-1) return -1;
    
    return rever+exit;
}