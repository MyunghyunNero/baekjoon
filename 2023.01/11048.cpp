#include <iostream>
#include <vector>
using namespace std;
int arr[1011][1011];
int d[1011][1011];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=m;k++){
            cin>>arr[i][k];
        }
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=m;k++){
            int value=arr[i][k];
            int maxValue=value;
            for(int j=0;j<3;j++){
                maxValue=max(d[i-1][k-1]+value,d[i-1][k]+value);
                maxValue=max(maxValue,d[i][k-1]+value);
            }
            d[i][k]=maxValue;
        }
    }
    cout<<d[n][m];

}