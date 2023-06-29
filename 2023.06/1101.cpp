#include <iostream>
#include <cstring>
using namespace std;
int n,m;
int arr[51][51];
int ans=987654321;
void dfs(int joker){
    int cnt=0;
    bool visited[51];
    memset(visited,false,sizeof(visited));
    for(int i=0;i<n;i++){
        if(i==joker) continue;
        int cardcnt=0;
        int check=0;
        for(int j=0;j<m;j++){
            if(arr[i][j]!=0){
                cardcnt++;
                check=j;
            }
        }
        if(cardcnt==0){
            continue;
        }else if(cardcnt==1){
            if(visited[check]){
                cnt++;
            }else{
                visited[check]=true;
            }
        }else{
            cnt++;
        }
    }
    if(ans>cnt){
        ans=cnt;
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        dfs(i);
    }
    cout<<ans;
}