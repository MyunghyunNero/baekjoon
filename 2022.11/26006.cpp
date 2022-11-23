// #include <iostream>
// #include <vector>
// using namespace std;
// int N,K;
// pair<int,int> white;
// vector<pair<int,int>> black;
// int check[3][3];
// int main(){
//     cin >> N >> K;
//     cin >> white.first >> white.second;
//     for(int i=0;i<K;i++){
//         int a,b;
//         cin>>a>>b;
//         black.push_back({a,b});
//     }

//     for(int i = -1 ; i<2;i++){
//         for(int j=-1 ; j<2;j++){
//             if(white.first+i <=n && white.first+i >0 && white.second + j <=n && white.second +j >0){
//                 check[i+1][j+1]=1;
//                 for(int t=0;t<K;t++){
//                     int row = white.first + i -black[t].first;
//                     int col = white.second + j - black[t].second;
//                     if(row==0 || col ==0 || row/col ==1 || row/col == -1){
//                         check[i+1][j+1]=2;
//                         break;
//                     }
//                 }
//             }
//         }
//     }
//     bool before,after;
//     for(int i=0;i<3;i++){
//         for(int k=0;k<3;k++){}
//     }
// }

#include <iostream>
using namespace std;

int n, k, r , c, x, y;
int check[3][3];
bool before ;
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
            if(nx-x == 0 ||ny-y==0 || (nx-x)/(ny-y)==1 || (nx-x)/(ny-y)==-1){
                check[dx[s]+1][dy[s]+1] = 1;
            }
        }
    }


    for(int i=0;i<9;i++){
        if(i==4 && check[dx[i]+1][dy[i]+1]==1 ) {
            before=true;
            continue;}

        if(check[dx[i]+1][dy[i]+1]==0) after=false;
    }

    if(before && !after) cout <<"CHECK";
    else if(before && after) cout << "CHECKMATE";
    else if(!before && after) cout << "STALEMATE";
    else cout <<"NONE";
}