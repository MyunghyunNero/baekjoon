#include <iostream>
#include <vector>
using namespace std;
int n;
int x,y,d,g;
int arr[102][102];
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
int ans;
vector<int> v;
int turnd(int direct){
    if(direct==3){
        return 0;
    }else{
        return direct+1;
    }
}
void dfs(int gel){
    if(gel==g){
        return;
    }
    int len=v.size();
    for(int i=len-1;i>=0;i--){
        int dir=turnd(v[i]);
        x=x+dx[dir];
        y=y+dy[dir];
        arr[x][y]=1;
        v.push_back(dir);
    }
    dfs(gel+1);

}
int main(){
    cin>>n;
    while(n--){
        v.clear();
        g=0;
        cin>>y>>x>>d>>g;
        arr[x][y]=1;
        arr[x+dx[d]][y+dy[d]]=1;
        x=x+dx[d];
        y=y+dy[d];
        v.push_back(d);
        dfs(0);
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(arr[i][j]==1 && arr[i+1][j]==1 && arr[i][j+1]==1 && arr[i+1][j+1]==1){
                ans++;
            }
        }
    }
    cout<<ans;
}