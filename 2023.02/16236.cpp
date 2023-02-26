#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int n;
int arr[21][21];
bool check[21][21];
int cnt;
int startx,starty;
int shark=2;
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    if(a.second<b.second){
        return true;
    }else if(a.second==b.second){
        if(a.first.first<b.first.first){
            return true;
        }else if(a.first.first==b.first.first){
            if(a.first.second<b.first.second){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}
int res=0;
int bfs(int a,int b){
    queue<pair<pair<int,int>,int>> q;
    vector<pair<pair<int,int>,int>> v;
    memset(check,false,sizeof(check));
    arr[a][b]=0;
    q.push({{a,b},0});
    check[a][b]=true;
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int dist=q.front().second;
        q.pop();
        if(arr[x][y]!=0 && arr[x][y]<shark){
            v.push_back({{x,y},dist});
        }
        for(int i=0;i<4;i++){
            int nx= x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(check[nx][ny]==false && arr[nx][ny]<=shark){
                q.push({{nx,ny},dist+1});
                check[nx][ny]=true;
            }
        }
    }
    int d=0;
    sort(v.begin(),v.end(),cmp);
    if(!v.empty()){
        startx=v[0].first.first;
        starty=v[0].first.second;
        d=v[0].second;
        cnt++;
        if(cnt==shark){
            shark++;
            cnt=0;
        }
    }
    return d;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]==9){
                startx=i;
                starty=j;
            }
        }
    }
    while(1){
        int ans=bfs(startx,starty);
        if(ans==0){
            break;
        }
        res+=ans;
    }
    cout<<res;

}