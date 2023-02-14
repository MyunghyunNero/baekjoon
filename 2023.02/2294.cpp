#include <iostream>
using namespace std;
int n,k;
int arr[101][10001];
int main(){
    cin>>n>>k;
    for(int i=1;i<=10000;i++){
        arr[0][i]=999999999;
    }
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        for(int j=1;j<=k;j++){
            if(j<a){
                arr[i][j]=arr[i-1][j];
            }else{
                arr[i][j]=min(arr[i-1][j],arr[i][j-a]+1);
            }
        }
    }
    if(arr[n][k]==999999999){
        cout<<-1;
    }else{
        cout<<arr[n][k];
    }
}
