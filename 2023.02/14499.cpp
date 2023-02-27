#include <iostream>
#include <vector>
using namespace std;
int arr[21][21];
int n,m,k;
int startx,starty;
vector<int> dice(6);//위 , 아래, 동,서,남,북
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
void movedice(int m){
    if(m==1){
        dice={dice[3],dice[2],dice[0],dice[1],dice[4],dice[5]};
    }else if(m==2){
        dice = {dice[2],dice[3],dice[1],dice[0],dice[4],dice[5]};
    }else if(m==3){
        dice={dice[4],dice[5],dice[2],dice[3],dice[1],dice[0]};
    }else if(m==4){
        dice={dice[5],dice[4],dice[2],dice[3],dice[0],dice[1]};
    }
}
int main(){
    cin>>n>>m>>startx>>starty>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<k;i++){
        int move;
        cin>>move;
        startx=startx+dx[move-1];
        starty=starty+dy[move-1];
        if(startx<0 || startx>=n || starty<0 || starty>=m) {
            startx-=dx[move-1];
            starty-=dy[move-1];
            continue;
        }
        movedice(move);
        if(arr[startx][starty]==0){
            arr[startx][starty]=dice[1];
        }else{
            dice[1]=arr[startx][starty];
            arr[startx][starty]=0;
        }
        

        cout<<dice[0]<<'\n';
    }
}
