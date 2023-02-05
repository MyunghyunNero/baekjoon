#include <iostream>
#include <vector>
using namespace std;
char arr[101][101];
int timeArr[101][101];
int main(){
    int h,w;
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='.') timeArr[i][j]=-1;
            else timeArr[i][j]=0;
        }
    }
    for(int i=0;i<h;i++){
        int day=-1;
        for(int j=0;j<w;j++){
            if(arr[i][j]=='c') day=0;
            if(day!=-1 && arr[i][j]=='.') timeArr[i][j]=++day;
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<timeArr[i][j]<<' ';
        }
        cout<<'\n';
    }
}