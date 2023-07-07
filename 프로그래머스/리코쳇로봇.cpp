#include <string>
#include <vector>
#include <queue>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool visited[101][101];
int rsize;
int csize;
int ans=-1;
void bfs(int r,int c,vector<string> arr){
    visited[r][c]=true;
    queue<pair<pair<int,int>,int>> q;
    q.push({{r,c},0});
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int d=q.front().second;
        q.pop();
        if(arr[x][y]=='G'){
            ans=d;
            break;
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=rsize || nx<0 || ny>=csize || ny<0 || arr[nx][ny]=='D'){
                continue;
            }
            while(nx+dx[i]<rsize && ny+dy[i]<csize && nx+dx[i]>=0 && ny+dy[i]>=0 && arr[nx+dx[i]][ny+dy[i]]!='D'){
                nx=nx+dx[i];
                ny=ny+dy[i];
            }
            if(!visited[nx][ny]){
                visited[nx][ny]=true;
                q.push({{nx,ny},d+1});
            }
        }
    }
}
int solution(vector<string> board) {
    rsize=board.size();
    csize=board[0].size();
    for(int i=0;i<rsize;i++){
        for(int j=0;j<csize;j++){
            if(board[i][j]=='R'){
                bfs(i,j,board);
            }
        }
    }
    return ans;
}