#include <iostream>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m,cnt,t,a,b;
int arr[51][51];
bool visit[51][51];
void reset() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visit[i][j] = 0;
        }
    }
}
 
void dfs(int y,int x){
    visit[y][x]=true;
    for(int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny>=0 && ny<n && nx>=0 && nx<m){
            if(arr[ny][nx] && !visit[ny][nx]){
                dfs(ny,nx);
            }
        }
    }
}
int main(){
    cin>>t;
    while(t--){
        reset();
        int ans=0;
        cin>>n>>m>>cnt;
        for(int i=0;i<cnt;i++){
            cin>>a>>b;
            arr[a][b]=1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]&&!visit[i][j]){
                    ans++;
                    dfs(i,j);
                }
            }
        }
        cout<<ans<<'\n';
    }
}