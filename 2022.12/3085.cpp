#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
int ans;
char arr[51][51];
int findMax(){
    int M=1;
    for(int i=0;i<n;i++){
        int index=1;
        for(int j=1;j<n;j++){
            if(arr[i][j-1]==arr[i][j]){
                index++;
                if(M<index) M=index;
            }else{
                index=1;
            }
        }
    }
    for(int j=0;j<n;j++){
        int index=1;
        for(int i=1;i<n;i++){
            if(arr[i-1][j]==arr[i][j]){
                index++;
                if(M<index) M=index;
            }else{
                index=1;
            }
        }
    }
    return M;
}
void swap(int i,int j,int x,int y){
    char temp = arr[i][j];
    arr[i][j]=arr[x][y];
    arr[x][y]=temp;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    ans = findMax();
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            swap(i,j-1,i,j);
            int temp = findMax();
            if(ans<temp) ans=temp;
            swap(i,j-1,i,j);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            swap(j-1,i,j,i);
            int temp = findMax();
            if(ans<temp) ans=temp;
            swap(j-1,i,j,i);
        }
    } 
    cout<<ans;

}