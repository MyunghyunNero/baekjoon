#include <iostream>
using namespace std;
bool queen[16][16];
int ans;
bool check(int row,int column,int n){  //열,행,체스판 크기
    for(int i=1;i<=n;i++){
        if(queen[column][i]){    //같은 열에 퀸이 있음
            return false; 
        }
        if(queen[i][row]){             //같은 행에 퀸이 있음
            return false;
        }
        if(column>i&&row>i&&queen[column-i][row-i]){     //왼쪽 위 대각선에 퀸이 있음
            return false;
        }
        if(column>i&&row+i<=n&&queen[column-i][row+i]){     //오른쪽 위 대각선에 퀸이 있음
            return false;
        }
    }
    return true;
} 
void go(int row,int column,int n){ //열,행,체스판 크기,퀸개수
    if(column==n+1){
        ans++;
    }
    for(int k=1;k<=n;k++){
        if(check(k,column,n)){
            queen[column][k]=true;
            go(row,column+1,n);
        }
        queen[column][k]=false;
    }
}
int main(){
    int n;
    cin>>n;
    go(1,1,n);
    cout<<ans;
}
