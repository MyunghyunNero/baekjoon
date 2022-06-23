#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
int arr[10];
bool check[10];
void dfs(int num,int cnt){
    if(cnt==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<' ';
        }
        cout << '\n';
        return;
    }
    for(int i=num;i<=n;i++){
        if(!check[i]){
            check[i]=true;
            arr[cnt]=i;
            dfs(i+1,cnt+1);
            check[i]=false;
        }
    }
}
int main(){
    cin >>n>>m;
    dfs(1,0);
}