#include <bits/stdc++.h>
using namespace std;
int b[1001][1001];
int h,w,x,y;
int main(){
    cin>>h>>w>>x>>y;
    for(int i=0;i<h+x;i++){
        for(int k=0;k<w+y;k++){
            cin>>b[i][k];
        }
    }
    for(int i=0;i<h;i++){
        for(int k=0;k<w;k++){
            if(i>=x && k>=y) b[i][k]-=b[i-x][k-y];
            cout<<b[i][k]<<" ";
        }
        cout<<'\n';
    }


}