#include <iostream>
#include <string>
#include <vector>
using namespace std;
char arr[201][201];
int bombTime[201][201];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int r,c,n;
void deleteBomb(int t){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(bombTime[i][j]==t){
                for(int k=0;k<4;k++){
                    int nx= i+dx[k];
                    int ny = j+dy[k];
                    if(nx<0||ny<0||nx>=r||ny>=c) continue;
                    if(arr[nx][ny]=='.') continue;
                    arr[nx][ny]='.';
                }
                arr[i][j]='.';
                bombTime[i][j]=0;  
            }
        }
    }
}
void installBomb(int t){
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 'O') continue;
            arr[i][j] = 'O';
            bombTime[i][j]= t + 3;
        }
    }
}
int main(){
    cin>>r>>c>>n;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='O'){
                bombTime[i][j]=3;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(i%2==0){
            installBomb(i);
        }else{
            deleteBomb(i);
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr[i][j];
        }
        cout<<'\n';
    }
}