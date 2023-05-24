#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int n;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<string> v;
int arr[101][101];
int cnt=1;
int noans;   //적록색맹 없음
int yesans;   //적록색맹 있음
void bfs(int a,int b){
    queue<pair<int,int>> q;
    arr[a][b]=cnt;
    char color = v[a][b];
    q.push({a,b});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=n || nx<0 || ny>=n || ny<0 ) continue;
            if(!arr[nx][ny] && v[nx][ny]==color){
                q.push({nx,ny});
                arr[nx][ny]=cnt;
            }
        }

    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!arr[i][j]){
                bfs(i,j);
                cnt++;
            }
        }
    }
    noans=cnt-1;
    cnt=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=0;
            if(v[i][j]=='R'){
                v[i][j]='G';
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!arr[i][j]){
                bfs(i,j);
                cnt++;
            }
        }
    }
    yesans=cnt-1;
    cout<<noans<<' '<<yesans;
}