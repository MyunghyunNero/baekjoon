#include <string>
#include <vector>

using namespace std;

bool visited[6][6];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<vector<int>> arr;
int rboardsize;
int cboardsize;
int ans;
int dfs(int ax,int ay,int bx,int by){
    if(visited[ax][ay]) return 0;
    int ret=0;
    for(int i=0;i<4;i++){
        int nx=ax+dx[i];
        int ny=ay+dy[i];
        if(nx<0 || nx>=rboardsize || ny<0 || ny>=cboardsize) continue;
        if(arr[nx][ny]==0) continue;
        if(visited[nx][ny]) continue;
        visited[ax][ay]=true;
        int val=dfs(bx,by,nx,ny)+1;
        visited[ax][ay]=false;
        
        if(ret%2==0 && val%2==1) ret=val;
        else if(ret%2==0 && val%2==0) ret=max(ret,val);
        else if(ret%2==1 && val%2==1) ret=min(ret,val);
    }
    return ret;
}
int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = -1;
    arr=board;
    rboardsize=board.size();
    cboardsize=board[0].size();
    
    return dfs(aloc[0],aloc[1],bloc[0],bloc[1]);
}