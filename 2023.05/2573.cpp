#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int arr[301][301];
int mi[301][301];
bool check[301][301];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m;
void bfs(int s,int e){
    queue<pair<int,int>> q;
    q.push({s,e});
    check[s][e]=true;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        int cnt=0;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=n||nx<0||ny>=m || ny<0) continue;
            if(arr[nx][ny]>0 && !check[nx][ny]){
                q.push({nx,ny});
                check[nx][ny]=true;
            }
            if(arr[nx][ny]<=0) cnt++;
        }
        mi[x][y]=cnt;
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int ans=0;
    while(1){
        int div=0;
        memset(mi,0,sizeof(mi));
        memset(check,false,sizeof(check));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]>0 && !check[i][j]){
                    div++;
                    bfs(i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            	if(arr[i][j]>0){
                int num=arr[i][j]-mi[i][j];
                num=num<0 ? 0:num;
                arr[i][j]=num;
            	}
            }
        }
        for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++){
        		cout<<arr[i][j]<<' ';
        	}
        	cout<<'\n';
        }
        cout<<'\n'<<ans<<'\n';
        if(div>1){
            break;
        }else if(div==0){
            ans=0;
            break;
        }
        ans++;
    }
    cout<<ans;
}