#include <iostream>
#include <queue>
using namespace std;
int arr[101][101];
bool check[101][101];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m,t,ans=987654321;
pair<int,int> weopon;
int weoponD=987654321;
void bfs(){
    queue<pair<pair<int,int>,int>> q;
    q.push({{1,1},0}); 
    check[1][1]=true;
    if(arr[1][1]==2){
        weoponD=0;
    }
    while(!q.empty()){
        int x= q.front().first.first;
        int y=q.front().first.second;
        int d= q.front().second;
        q.pop();
        if(arr[x][y]==2){
            weoponD=d;
        }
        if(x==n && y==m){
            ans=min(ans,d);
            return;
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<1||nx>n || ny<1||ny>m) continue;
            if(arr[nx][ny]==1) continue;
            if(!check[nx][ny]){
                q.push({{nx,ny},d+1});
                check[nx][ny]=true;
            }
        }
    }
}
int main(){
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            if(arr[i][j]==2){
                weopon={i,j};
            }
        }
    }
    bfs();
    ans=min(ans,weoponD+(n-weopon.first)+(m-weopon.second));
    if(ans<=t){
         cout<<ans;
    }else{
        cout<<"Fail";
    }
   
}