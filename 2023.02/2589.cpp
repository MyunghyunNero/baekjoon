#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n,m;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
char arr[51][51];
bool check[51][51];
int bfs(int i,int j){
    queue<pair<pair<int,int>,int>> q;
    int maxd=0;
    q.push({{i,j},0});
    check[i][j]=true;
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int d = q.front().second;
        q.pop();
        if(maxd<d) maxd=d;
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny= y+dy[i];
            int dd=d+1;
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(check[nx][ny]==false && arr[nx][ny]=='L'){
                q.push({{nx,ny},dd});
                check[nx][ny]=true;
            }
        }
    }
    return maxd;
}
int main(){
    cin>>n>>m;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            memset(check,false,sizeof(check));
            if(arr[i][j]=='L'){
                int d=bfs(i,j);
                if(ans<d){
                    ans=d;
                }
            }
        }
    }
    cout<<ans;
}