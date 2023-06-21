#include <iostream>
#include <vector>
using namespace std;
int arr[51][5];
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
int r1,c1,r2,c2;

int main(){
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    int x=0,y=0;
    int len=1;
    int cnt=1;
    if(r1<=x && x<=r2 && c1<=y && y<=c2){
        arr[x-r1][y-c1]=cnt;
    }
    cnt++;
    int curlen=0;
    int dir=0;
    while(arr[0][0]==0 || arr[r2-r1][0]==0 || arr[r2-r1][c2-c1]==0 || arr[0][c2-c1]==0){
        x+=dx[dir];
        y+=dy[dir];
        if(r1<=x && x<=r2 && c1<=y && y<=c2){
            arr[x-r1][y-c1]=cnt;
        }
        cnt++;
        curlen++;
        if(curlen==len){
            curlen=0;
            dir++;
            dir%=4;
            if(dir==0 ||dir ==2 ){
                len++;
            }
        }
    }
    int space = 0;
	while (cnt != 0) {
		cnt /= 10;
		space++;
	}
    for(int i=0;i<=r2-r1;i++){
        for(int j=0;j<=c2-c1;j++){
            printf("%*d ", space, arr[i][j]);
        }
        printf("\n");
    }
}