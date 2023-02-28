#include <iostream>
#include <cstring>
using namespace std;
int arr[101][101];
int arr2[101][101];
bool setup[101][101];
int n,l;
int ans;
int main(){
    cin>>n>>l;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            arr2[i][j]=arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        bool check=true;
        for(int j=1;j<n;j++){
            if((arr[i][j]-arr[i][j-1])==1){
                int cmpv=arr[i][j]-1;
                for(int k=j-1;k>=j-l;k--){
                    if(k<0){
                        check=false;
                        break;
                    }
                    if(setup[i][k]){
                        check=false;
                        break;
                    }
                    if(arr[i][k]!=cmpv) {
                        check=false;
                        break;
                    }else{
                        setup[i][k]=true;
                    }

                }
            }else if(arr[i][j]==arr[i][j-1]) {
                continue;
            }else if(abs(arr[i][j]-arr[i][j-1])>1){
                check=false;
                break;
            }else{
                continue;
            }
        }
        for(int j=n-2;j>=0;j--){
            if((arr[i][j]-arr[i][j+1])==1){
                int cmpv=arr[i][j]-1;
                for(int k=j+1;k<=j+l;k++){
                    if(k>=n){
                        check=false;
                        break;
                    }
                    if(setup[i][k]){
                        check=false;
                        break;
                    }
                    if(arr[i][k]!=cmpv) {
                        check=false;
                        break;
                    }else{
                        setup[i][k]=true;
                    }
                }
            }else if(arr[i][j]==arr[i][j+1]) {
                continue;
            }else if(abs(arr[i][j]-arr[i][j+1])>1){
                check=false;
                break;
            }else{
                continue;
            }
        }
        if(check){
            ans+=1;
        }
    
    }
    memset(setup,false,sizeof(setup));
    for(int i=0;i<n;i++){
        bool check=true;
        for(int j=1;j<n;j++){
            if((arr2[j][i]-arr2[j-1][i])==1){
                int cmpv=arr2[j][i]-1;
                for(int k=j-1;k>=j-l;k--){
                    if(k<0){
                        check=false;
                        break;
                    }
                    if(setup[k][i]) {
                        check=false;
                        break;
                    }
                    if(arr2[k][i]!=cmpv) {
                        check=false;
                        break;
                    }else{
                        setup[k][i]=true;
                    }

                }
            }else if(arr2[j][i]==arr2[j-1][i]) {
                continue;
            }else if(abs(arr2[j][i]-arr2[j-1][i])>1){
                check=false;
                break;
            }else{
                continue;
            }
        }
        for(int j=n-2;j>=0;j--){
            if((arr2[j][i]-arr2[j+1][i])==1){
                int cmpv=arr2[j][i]-1;
                for(int k=j+1;k<=j+l;k++){
                    if(k>=n){
                        check=false;
                        break;
                    }
                    if(setup[k][i]){
                        check=false;
                        break;
                    }
                    if(arr2[k][i]!=cmpv) {
                        check=false;
                        break;
                    }else{
                        setup[k][i]=true;
                    }
                }
            }else if(arr2[j][i]==arr2[j+1][i]) {
                continue;
            }else if(abs(arr2[j][i]-arr2[j+1][i])>1){
                check=false;
                break;
            }else{
                continue;
            }
        }
        if(check){
            ans+=1;
        }
    }
    cout<<ans;
}  