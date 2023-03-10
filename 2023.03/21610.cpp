#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int arr[101][101];
bool cloud[101][101];
int dx[]={0,0,-1,-1,-1,0,1,1,1};
int dy[]={0,-1,-1,0,1,1,1,0,-1};
int dix[]={-1,-1,1,1};
int diy[]={-1,1,-1,1};
vector<pair<int,int>> c;
int n,m;
void makeCloud(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]>=2 && cloud[i][j]==false){
                c.push_back({i,j});
                arr[i][j]-=2;
            }
        }
    }
}
int sumCloud(){
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum+=arr[i][j];
        }
    }
    return sum;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    c.push_back({n,1});
    c.push_back({n,2});
    c.push_back({n-1,1});
    c.push_back({n-1,2});
    while(m--){
        int d,s;
        cin>>d>>s;
        memset(cloud,false,sizeof(cloud));
        vector<pair<int,int>> movecloud;
        for(int i=0;i<c.size();i++){
            int x=c[i].first;
            int y=c[i].second;
            int nx= x+ s*dx[d];
            int ny= y+ s*dy[d];
            nx=(nx%n==0) ? n : nx%n;
            if(nx<1){
            	nx=(nx%n==0) ? n : n+nx%n;
            }else{
            	nx=(nx%n==0) ? n : nx%n;
            }
            if(ny<1){
            	ny=(ny%n==0) ? n : n+ny%n;
            }else{
            	ny=(ny%n==0) ? n : ny%n;
            }
            arr[nx][ny]++;
            movecloud.push_back({nx,ny});
        }
        for(int i=0;i<movecloud.size();i++){
            int x=movecloud[i].first;
            int y=movecloud[i].second;
            cloud[x][y]=true;
            int cnt=0;
            for(int j=0;j<4;j++){
                int nx=x+dix[j];
                int ny=y+diy[j];
                if(nx>n||nx<=0||ny>n||ny<=0) continue;
                if(arr[nx][ny]>0) cnt++;
            }
            arr[x][y]+=cnt;
        }
        c.clear();
        makeCloud();
    }
    cout<<sumCloud();
}