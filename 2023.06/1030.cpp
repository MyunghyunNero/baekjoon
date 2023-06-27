#include <iostream>
#include <cmath>
using namespace std;
int s,n,k,r1,r2,c1,c2;
int arr[100][100];
void recur(int time,int r,int c,int color){
	int size=pow(n,time);
    int left=(n-k)/2;
	if(r2<r || c2<c || r+size<r1 || c+size<c1) return;
    if(time==0){
        arr[r-r1][c-c1]=color;
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int ncolor=color;
            if(left<=i && i<left+k &&left<=j && j<left+k ){
                ncolor=1;
            }
            recur(time-1,r+i*(size/n),c+j*(size/n),ncolor);
        }
    }
}
int main(){
    cin>>s>>n>>k>>r1>>r2>>c1>>c2; 
    recur(s,0,0,0);
    for(int i=0;i<=r2-r1;i++){
        for(int j=0;j<=c2-c1;j++){
            cout<<arr[i][j];
        }
        cout<<'\n';
    }
}