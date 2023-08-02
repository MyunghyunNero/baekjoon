#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<string> arr;
vector<int> ans;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int r,c;
bool visited[101][101];
void bfs(int startx,int starty){
    queue<pair<int,int>> q;
    q.push({startx,starty});
    visited[startx][starty]=true;
    int sum=0;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        sum+=arr[x][y]-'0';
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx <0 || nx >=r || ny<0 || ny>=c) continue;
            if(arr[nx][ny]=='X') continue;
            if(!visited[nx][ny]){
                q.push({nx,ny});
                visited[nx][ny]=true;
            }
        }
    }
    if(sum>0){
        ans.push_back(sum);
    }
}
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    arr=maps;
    r=maps.size();
    c=maps[0].size();
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(!visited[i][j] && arr[i][j]!='X'){
                bfs(i,j);
            }
        }
    }
    sort(ans.begin(),ans.end());
    if(ans.empty()){
        ans.push_back(-1);
    }
    return ans;
}