#include <cstdio>
using namespace std;
char alpa[20][20];
bool check[26];
int r,c;
int max;
void go(int row,int col,int i){                    //row는 열 ,col은 행, i는 몇번째 인지
    check[alpa[col][row]-'A']=true;
    if(max<i){                                             
        max=i;
    }
    if(row-1>=0&&check[alpa[col][row-1]-'A']==false){          //왼쪽으로 이동
        go(row-1,col,i+1);                        
    }
    if(row+1<c&&check[alpa[col][row+1]-'A']==false){          //오른쪽으로 이동
        go(row+1,col,i+1);
    }
    if(col-1>=0&&check[alpa[col-1][row]-'A']==false){         //위쪽으로 이동
        go(row,col-1,i+1);
    }
    if(col+1<r&&check[alpa[col+1][row]-'A']==false){        //아래쪽으로 이동
        go(row,col+1,i+1);
    }
    check[alpa[col][row]-'A']=false;                    //다들렸으면 들른 알파벳 빼주기
    return;
}
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++){
        for(int k=0;k<c;k++){
            scanf(" %1c",&alpa[i][k]);
        }
    }
    go(0,0,1);
    printf("%d",max);
    return 0;
}