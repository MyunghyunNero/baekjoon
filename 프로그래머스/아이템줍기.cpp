#include <string>
#include <vector>
#include <queue>

using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int arr[101][101];
bool check[101][101];
int ans=-1;
void dfs(int cx,int cy,int desx,int desy){
    check[cx*2][cy*2]=true;
    queue<pair<pair<int,int>,int>> q;
    q.push({{cx*2,cy*2},0});
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int d=q.front().second;
        q.pop();
        if(x==desx*2 && y==desy*2){
            ans=d;
            return;
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || nx>100 || ny<0 || ny>100) continue;
            if(!check[nx][ny] && arr[nx][ny]==1){
                check[nx][ny]=true;
                q.push({{nx,ny},d+1});
            }
        }
    }
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    for(int i=0;i<rectangle.size();i++){
        for(int j=rectangle[i][0]*2; j <= rectangle[i][2]*2; j++){
            for(int k=rectangle[i][1]*2;k<=rectangle[i][3]*2;k++){
                if(j==rectangle[i][0]*2 || j==rectangle[i][2]*2){
                    arr[j][k]=1;
                }else if(k==rectangle[i][1]*2 || k==rectangle[i][3]*2){
                    arr[j][k]=1;
                }else{
                    arr[j][k]=0;
                }
            }
        }
    }
    for(int i=0;i<rectangle.size();i++){
        for(int j=rectangle[i][0]*2+1; j < rectangle[i][2]*2; j++){
            for(int k=rectangle[i][1]*2+1;k<rectangle[i][3]*2;k++){
                    arr[j][k]=0;
            }
        }
    }
    dfs(characterX,characterY,itemX,itemY);
    return ans/2;
}