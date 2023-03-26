#include <iostream>
#include <string>
using namespace std;
int arr[1001][1001];
int n,m;


int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            arr[i][j]=s[j]-'0';
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][j]==0) continue;
            else{
                arr[i][j]=min(arr[i-1][j],min(arr[i-1][j-1],arr[i][j-1]))+1;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans=max(ans,arr[i][j]);
        }
    }
    cout<<ans*ans;
}