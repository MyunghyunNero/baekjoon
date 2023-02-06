#include <iostream>
#include <set>
using namespace std;
int n;
int arr[4]={1,5,10,50};
bool visit[1101];
int ans;
void dfs(int depth,int val,int sum){
    if(depth==n){
        if(visit[sum]==false){
            visit[sum]=true;
            ans++;
        }
        return;
    }
    for(int i=val;i<4;i++){
        dfs(depth+1,i,sum+arr[i]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    dfs(0,0,0);
    cout<<ans;
}