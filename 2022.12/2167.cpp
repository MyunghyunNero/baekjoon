#include <iostream>
using namespace std;
int n,m;
int sum[302][302];
int main(){
    cin >> n>>m;
    int accSum=0;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=m;k++){
            int a;
            cin>>a;
            accSum=(a+sum[i-1][k]+sum[i][k-1]-sum[i-1][k-1]);
            sum[i][k]=accSum;
        }
    }

    int t;
    cin>>t;
    while(t--){
        int i,j,x,y;
        cin>>i>>j>>x>>y;
        cout << sum[x][y]-sum[i-1][y]-sum[x][j-1]+sum[i-1][j-1]<<'\n';
    }
}