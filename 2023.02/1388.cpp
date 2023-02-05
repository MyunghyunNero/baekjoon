#include <iostream>
using namespace std;
char arr[51][51];
int ans;
int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        int cnt=0;
        bool check=false;
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='-'&& !check) check=true;
            else if(arr[i][j]=='|' && check){
                check=false;
                cnt++;
            }
        }
        if(check) ans += cnt+1;
        else ans+=cnt;
    }
    for(int i=0;i<m;i++){
        int cnt=0;
        bool check=false;
        for(int j=0;j<n;j++){
            if(arr[j][i]=='|' && !check) check=true;
            else if(arr[j][i]=='-' && check){
                check=false;
                cnt++;
            }
        }
        if(check) ans += cnt+1;
        else ans+=cnt;
    }
    cout<<ans;
}