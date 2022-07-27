#include <iostream>
#include <algorithm>
using namespace std;
bool dp[31][15001];
int n,m,weight[31];
void solve(int i,int w){
    if(i>n||dp[i][w]){
        return;
    }
    dp[i][w]=true;
    solve(i+1,w+weight[i]);
    solve(i+1,abs(w-weight[i]));
    solve(i+1,w);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    solve(0,0);
    cin>>m;
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        if(a>15000){
            cout<<'N'<<'\n';
        }
        else if(dp[n][a]){
            cout << 'Y'<<'\n';
        }else{
            cout<<'N'<<'\n';
        }
    }
}