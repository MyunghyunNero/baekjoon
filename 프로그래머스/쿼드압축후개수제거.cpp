#include <string>
#include <vector>
#include <iostream>
using namespace std;
int zeroCnt=0;
int oneCnt=0;
vector<vector<int>> arrs;
void zip(int x,int y,int size) {
    if(size <= 1){
        return;
    }
    bool check = true;
    int preValue = arrs[x][y];
    for(int i=x;i<x+size;i++) {
        for(int j=y;j<y+size; j++) {
            if(preValue != arrs[i][j]){
                check=false;
                break;
            }
            preValue = arrs[i][j];
        }
    }
    
    if(check) {
        if(preValue == 0 ){
            zeroCnt-=(size*size-1);
        }
        if(preValue==1){
            oneCnt-=(size*size-1);
        }
        return;
    }
    zip(x,y,size/2);
    zip(x+size/2,y,size/2);
    zip(x,y+size/2,size/2);
    zip(x+size/2,y+size/2,size/2);
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    arrs = arr;
    int size = arr.size();
    for(int i=0;i<size;i++) {
        for(int j=0;j<size; j++) {   
            if(arrs[i][j]==0){
                zeroCnt++;
            }
            if(arrs[i][j]==1){
                oneCnt++;
            }
        }   
    }
    zip(0,0,size);
    answer.push_back(zeroCnt);
    answer.push_back(oneCnt);
    return answer;
}