#include <iostream>
using namespace std;
char arr[11][11];
char temp[11][11];
int r,c;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void changeX(){
    for(int i=0;i<r;i++){
        for(int k=0;k<c;k++){
            int cnt=0;
            for(int j=0;j<4;j++){
                int nx=i+dx[j];
                int ny=k+dy[j];
                if(nx<0 || nx>=r || ny<0 || ny>=c) {
                    cnt++;
                    continue;
                    }
                if(temp[nx][ny]=='.') cnt++;
            }
            if(cnt>=3){
                arr[i][k]='.';
            }
        }
    }
}
int main(){
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int k=0;k<c;k++){
            cin>>arr[i][k];
            temp[i][k]=arr[i][k];
        }
    }
    changeX();
    int minx=11;
    int miny=11;
    int maxx=0;
    int maxy=0;
    for(int i=0;i<r;i++){
        for(int k=0;k<c;k++){
            if(arr[i][k]=='X'){
                if(minx>i)minx=i;
                if(miny>k)miny=k;
                if(maxx<i)maxx=i;
                if(maxy<k)maxy=k;
            }
        }
    }
    for(int i=minx;i<=maxx;i++){
        for(int k=miny;k<=maxy;k++){
            cout<<arr[i][k];
        }
        cout<<'\n';
    }
}