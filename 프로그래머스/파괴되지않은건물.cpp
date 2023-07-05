#include <string>
#include <vector>
#include <iostream>
using namespace std;
int arr[1002][1002];
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int rsize=board.size();
    int csize=board[0].size();
    int skillsize=skill.size();
    for(int i=0;i<skillsize;i++){
        int team=skill[i][0];
        int r1=skill[i][1];
        int c1=skill[i][2];
        int r2=skill[i][3];
        int c2=skill[i][4];
        int degree=skill[i][5];
        if(team==1){
            arr[r1][c1]-=degree;
            arr[r1][c2+1]+=degree;
            arr[r2+1][c1]+=degree;
            arr[r2+1][c2+1]-=degree;
        }else{
            arr[r1][c1]+=degree;
            arr[r1][c2+1]-=degree;
            arr[r2+1][c1]-=degree;
            arr[r2+1][c2+1]+=degree;
        }
    }
    for(int i=0;i<rsize;i++){
        for(int j=1;j<csize;j++){
            arr[i][j]+=arr[i][j-1];
        }
    }
    for(int i=0;i<csize;i++){
        for(int j=1;j<rsize;j++){
            arr[j][i]+=arr[j-1][i];
        }
    }
    for(int i=0;i<rsize;i++){
        for(int j=0;j<csize;j++){
            if(board[i][j]+arr[i][j]>0) answer++;
        }
    }
    return answer;
}