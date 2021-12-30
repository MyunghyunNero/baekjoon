#include <cstdio>
using namespace std;
int a[50][50];
int b[50][50];
void change(int n,int m){                //3*3 타일 행렬 변환 함수
    for(int i=n;i<n+3;i++){
        for(int k=m;k<m+3;k++){
            if(a[i][k]==1){
                a[i][k]=0;
            }
            else if(a[i][k]==0){
                a[i][k]=1;
            }
        }
    }
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){            //a행렬 입력
        for(int k=0;k<m;k++){
            scanf("%1d",&a[i][k]);
        }
    }
    for(int i=0;i<n;i++){            //b행렬 입력
        for(int k=0;k<m;k++){
            scanf("%1d",&b[i][k]);
        }
    }
    int ans =0;
    for(int i=0;i<n-2;i++){
        for(int k=0;k<m-2;k++){
            if(a[i][k]!=b[i][k]){      //원소 (0,0)부터 a행렬이랑 b핼렬이 다르면 행렬 변환 
                ans++;
                change(i,k);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
            if(a[i][k]!=b[i][k]){        //a행렬 b행렬이 일치하지 않으면 -1
                ans=-1;
                break;
            }
        }
    }
    printf("%d",ans);

}