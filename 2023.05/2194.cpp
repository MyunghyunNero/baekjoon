#include <iostream>
#include <queue>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int arr[501][501];
bool check[501][501];
int n,m,a,b,k;
pair<int,int> start,e;
int ans;
void bfs(){
    queue<pair<pair<int,int>,int>> q;
    q.push({{start.first,start.second},0});
    check[start.first][start.second]=true;
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int d=q.front().second;
        if(x== e.first && y==e.second){
            break;
        }
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(ny+b-1>m ||ny<=0 || nx+a-1>n ||nx<=0) continue;
            if(check[nx][ny]) continue;
            bool flag=true;
            if(ny>y){
                for(int j=0;j<a;j++){
                    if(arr[nx+j][ny+b-1]==-1){
                        flag=false;
                        break;
                    }
                }
            }else if(ny<y){
                for(int j=0;j<a;j++){
                    if(arr[nx+j][ny]==-1){
                        flag=false;
                        break;
                    }
                }
            }else if(nx>x){
                for(int j=0;j<b;j++){
                    if(arr[nx+a-1][ny+j]==-1){
                        flag=false;
                        break;
                    }
                }
            }else if(nx<x){
                for(int j=0;j<b;j++){
                    if(arr[nx][ny+j]==-1){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                q.push({{nx,ny},d+1});
                arr[nx][ny]=d+1;
                check[nx][ny]=true;
            }
        }
    }
}
int main(){
    cin>>n>>m>>a>>b>>k;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        arr[x][y]=-1;  //장애물
    }
    int tempa,tempb;
    cin>>tempa>>tempb;
    start={tempa,tempb};
    cin>>tempa>>tempb;
    e={tempa,tempb};
    bfs();
    if(arr[e.first][e.second]==0){
        cout<<-1;
    }else{
        cout<<arr[e.first][e.second];
    }
    
}   