#include <iostream>
#include <vector>
using namespace std;
int arr[101][101];
int A,B,N,M;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
vector<pair<pair<int,int>,int>> v;
int changeR(int dir){
    if(dir==3){
        dir=0;
    }else{
        dir+=1;
    }
    return dir;
}
int changeL(int dir){
    if(dir==0){
        dir=3;
    }else{
        dir-=1;
    }
    return dir;
}
int main(){
    cin>>A>>B>>N>>M;
    for(int i=0;i<N;i++){
        int a,b;
        char c;
        cin>>a>>b>>c;
        arr[a][b]=i+1;
        int dir=0;
        if(c=='N'){
            dir=0;
        }else if(c=='E'){
            dir=1;
        }else if(c=='S'){
            dir=2;
        }else{
            dir=3;
        }
        v.push_back({{a,b},dir});
    }
    bool check=false;
    for(int i=0;i<M;i++){
        int a,c;
        char b;
        cin>>a>>b>>c;
        int x=v[a-1].first.first;
        int y=v[a-1].first.second;
        int dir=v[a-1].second;
        if(b=='L'){
            for(int i=0;i<c;i++){
                dir=changeL(dir);
            }
            v[a-1]={{x,y},dir};
        }else if(b=='R'){
            for(int i=0;i<c;i++){
                dir=changeR(dir);
            }
            v[a-1]={{x,y},dir};
        }else if(b=='F'){
            arr[x][y]=0;
            for(int i=0;i<c;i++){
                int nx=x+dx[dir];
                int ny=y+dy[dir];
           
                if(nx<=0 || ny<=0 || nx>A || ny>B) {
                    cout<< "Robot " << a <<" crashes into the wall";
                    check=true;
                    break;
                }

                if(arr[nx][ny]!=0 && !check){
                	check=true;
                    cout<<"Robot "<<a<<" crashes into robot "<<arr[nx][ny];
                    break;
                }
                x=nx;
                y=ny;
            }
            v[a-1]={{x,y},dir};
            arr[x][y]=a;
            
        }
        if(check){
            break;
        }
    }
    if(!check){
        cout<<"OK";
    }
}