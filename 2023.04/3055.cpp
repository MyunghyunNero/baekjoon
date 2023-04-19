#include <iostream>
#include <queue>
using namespace std;
char arr[51][51];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int r,c;
bool check=false;
int ans;
pair<int,int> d,x,s; //d는 고슴도치, x는 홍수 , s는 친구 집
queue<pair<pair<int,int>,int>> dq;
queue<pair<pair<int,int>,int>> xq;
void bfs(){
    int cnt=0;
    while(!dq.empty()){
        if(check){
            break;
        }
        
        int xqlen=xq.size();
        for(int i=0;i<xqlen;i++){
            int xqx,xqy;
            if(xq.front().second==cnt){
                xqx=xq.front().first.first;
                xqy=xq.front().first.second;
                xq.pop();
                for(int j=0;j<4;j++){
                    int nxqx=xqx+dx[j];
                    int nxqy=xqy+dy[j];
                    if(nxqx<0 ||nxqx>=r || nxqy<0 || nxqy>=c || arr[nxqx][nxqy]=='X' || arr[nxqx][nxqy]=='*' || arr[nxqx][nxqy]=='D') continue;
                    arr[nxqx][nxqy]='*';
                    xq.push({{nxqx,nxqy},cnt+1});
                }
            }
        }
        int dqlen=dq.size();
        for(int i=0;i<dqlen;i++){
            int dqx,dqy;
            if(dq.front().second==cnt){
                dqx=dq.front().first.first;
                dqy=dq.front().first.second;
                dq.pop();
                for(int j=0;j<4;j++){
                    int ndqx=dqx+dx[j];
                    int ndqy=dqy+dy[j];
                    if(ndqx<0 ||ndqx>=r || ndqy<0 || ndqy>=c || arr[ndqx][ndqy]=='X' || arr[ndqx][ndqy]=='*'||arr[ndqx][ndqy]=='S') continue;
                    if(arr[ndqx][ndqy]=='D'){
                        check=true;
                        ans=cnt+1;
                    }
                    arr[ndqx][ndqy]='S';
                    dq.push({{ndqx,ndqy},cnt+1});
                }
            }
        }
        
        cnt++;
    }
}
int main(){
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int k=0;k<c;k++){
            cin>>arr[i][k];
            if(arr[i][k]=='S'){
                dq.push({{i,k},0});
            }else if(arr[i][k]=='*'){
                xq.push({{i,k},0});
            }
        }
    }
    bfs();
    if(check){
        cout<<ans;
    }else{
        cout<<"KAKTUS";
    }
}