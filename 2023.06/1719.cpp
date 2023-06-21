#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321 
int n,m;
int arr[201][201];
int ans[201][201];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) arr[i][j]=0;
            else arr[i][j]=INF;
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[a][b]=c;
        arr[b][a]=c;
        ans[a][b]=b;
        ans[b][a]=a;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(arr[j][k]>arr[j][i]+arr[i][k]){
                    arr[j][k]=arr[j][i]+arr[i][k];
                    ans[j][k]=ans[j][i];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ans[i][j]==0){
                cout<<'- ';
            }else{
                cout<<ans[i][j]<<" ";
            }
        }
        cout<<'\n';
    }
}