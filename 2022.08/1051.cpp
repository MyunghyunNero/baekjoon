#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int arr[51][51];
int ans;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int k=0;k<m;k++){
            arr[i][k]=s[k]-'0';
        }
    }
    int t=min(n,m)-1;
    for(int i=t;i>=0;i--){
        if(ans>0) break;
        for(int k=0;k+i<n;k++){
            if(ans>0) break;
            for(int j=0;j+i<m;j++){
                if(arr[k][j]==arr[k][j+i]&&arr[k][j+i]==arr[k+i][j]&&arr[k+i][j]==arr[k+i][j+i]&&arr[k+i][j+i]==arr[k][j]){
                    ans=i;
                    break;
                }
            }
        }
    }
    cout<<(ans+1)*(ans+1);
}