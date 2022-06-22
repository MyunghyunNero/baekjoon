#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
int arr[10];
bool check[10];
void dfs(int cnt){
    if(cnt==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(!check[i]){
            check[i]=true;
            arr[cnt]=i;
            dfs(cnt+1);
            check[i]=false;
        }
    }
}
int main(){
    cin >>n>>m;
    dfs(0);
}