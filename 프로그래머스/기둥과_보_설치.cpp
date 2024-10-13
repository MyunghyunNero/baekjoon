#include <string>
#include <vector>
#include <iostream>
using namespace std;
pair<int,int> arr[101][101];
bool build(int x, int y,int type,int n) {
    if(type == 0) {
        if(y==0) return true;
        if(x>0 && arr[x-1][y].second) return true;
        if(y<n && arr[x][y].second) return true;
        if(y>0 && arr[x][y-1].first) return true;
    }
    else{
        if(y>0 && arr[x][y-1].first) return true;
        if(y>0 && x<n && arr[x+1][y-1].first) return true;
        if(x<n&& x>0 &&arr[x-1][y].second && arr[x+1][y].second) return true;
    }
    return false;
}
bool check_remove(int x,int y,int type,int n){
    if(type == 0){
        arr[x][y].first = 0;
    }else{
        arr[x][y].second = 0;
    }
    if(type == 0){
        if(y<n && arr[x][y+1].first==1 && !build(x,y+1,0,n)) return false;
        if(y<n && arr[x][y+1].second == 1 && !build(x,y+1,1,n)) return false;
        if(y<n && x>0 &&arr[x-1][y+1].second==1 && !build(x-1,y+1,1,n)) return false;
    }else{
        // 위에 기둥이 있을 때
        if (arr[x][y].first==1 && !build(x, y, 0, n)) return false;
        if (x < n && arr[x + 1][y].first==1 && !build(x + 1, y, 0, n)) return false;
        
        // 위에 다른 보와 연결되어 있을 때
        if (x > 0 && arr[x - 1][y].second==1 && !build(x - 1, y, 1, n)) return false;
        if (x < n && arr[x + 1][y].second==1 && !build(x + 1, y, 1, n)) return false;
    }
    return true;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for(int i=0;i<101;i++) {
        for(int j=0;j<101;j++) {
            arr[i][j]={0,0};
        }
    }
    for(vector<int> v : build_frame) {
        int x = v[0];
        int y = v[1];
        int type = v[2];
        int have = v[3];
        if(have == 1) {
            if(build(x,y,type,n)) {
                if(type ==0) {
                    arr[x][y].first = 1;
                }else{
                    arr[x][y].second = 1;
                }
            }
        }else {
            if(!check_remove(x,y,type,n)) {
                if(type ==0){
                    arr[x][y].first =1;
                }else {
                    arr[x][y].second=1;
                }
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(arr[i][j].first==1) {
                answer.push_back({i,j,0});
            }
            if(arr[i][j].second ==1) {
                answer.push_back({i,j,1});
            }
        }
    }
    return answer;
}