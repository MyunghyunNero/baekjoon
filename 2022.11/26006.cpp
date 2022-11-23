#include <iostream>
using namespace std;

long long n, k, r , c, x, y;
int check[3][3];
bool before =false;
bool after=true;

// 8방향 + 자기 자신 (0, 0)
int dx[] = {-1,-1,-1,0,0,0,1,1,1};
int dy[] = {-1,0,1,-1,0,1,-1,0,1};

int main(void){
    cin >> n >> k;
    cin >> r >> c;
    for(int i=0; i<k; i++){
        cin >> x >> y;
        for(int s = 0; s<9; s++){
            int nx = r + dx[s];
            int ny = c + dy[s];
            if(nx>n || ny>n || nx <1 || ny <1){
                check[dx[s]+1][dy[s]+1]=-1;
                continue;
            }
            // 로직 -> 얘가 나랑 연관이 있는지 기울기랑, 같은 행인지 
            if(nx-x == 0 ||ny-y==0 || (nx-x)==(ny-y) || (nx-x)==-(ny-y)){
                check[dx[s]+1][dy[s]+1] = 1;
            }
        }
    }

    if(check[1][1]==1) before =true;
    for(int i=0;i<9;i++){
        if(i==4) continue;
        if(check[dx[i]+1][dy[i]+1]==0) after=false;
    }

    if(before && !after) cout <<"CHECK";
    else if(before && after) cout << "CHECKMATE";
    else if(!before && after) cout << "STALEMATE";
    else cout <<"NONE";
}