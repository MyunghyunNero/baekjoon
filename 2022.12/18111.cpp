#include <iostream>
using namespace std;
int n,m,b;
int arr[501][501];
int block;
int ans = 999999999;
int main(){
    cin>>n>>m>>b;
    int minIndex =257;
    int maxIndex = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(minIndex>arr[i][j]) minIndex=arr[i][j];
            if(maxIndex<arr[i][j]) maxIndex=arr[i][j];
        }
    }
    for(int i=minIndex;i<=maxIndex;i++){
        int time=0;
        int blockSum=b;
        for(int j=0;j<n;j++){
            for(int t=0;t<m;t++){
                if(i<arr[j][t]) {
                    time += (2*(arr[j][t]-i));
                    blockSum+=(arr[j][t]-i);
                    }
                if(i>arr[j][t]) {
                    blockSum-=(i-arr[j][t]);
                    time+=(i-arr[j][t]);
                }
            }
        }
        if(blockSum<0) continue;
        if(ans>=time) {
        	ans=time;
			block=i;
        }
    }
    cout<<ans<< ' ' << block;
}