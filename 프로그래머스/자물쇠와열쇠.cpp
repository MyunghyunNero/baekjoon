#include <string>
#include <vector>
#include <iostream>
using namespace std;
int M;
int N;
vector<vector<int>> keyArr;
vector<vector<int>> lockArr;
void spin() {
    int tmp[21][21];
    for(int i=0;i<M;i++) {
        for(int j=0;j<M;j++) {
            tmp[j][M-i-1] = keyArr[i][j];
        }
    }
    for(int i=0;i<M;i++) {
        for(int j=0;j<M;j++) {
            keyArr[i][j] = tmp[i][j];
        }
    }
}
// a , b는 key의 첫 부분이 lock의 어디에 있는지 
// a >= -M+1 , b >= -M+1
bool check(int a,int b) {
    vector<vector<int>> tmp;
    tmp = lockArr;
    for(int i = a;i<a+M;i++){
        for(int j=b;j<b+M;j++) {
            if(i<0 || i>=N || j<0||j>=N) continue;
            tmp[i][j] ^= keyArr[i-a][j-b];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) {
            if(tmp[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    M = key.size();
    N = lock.size();
    keyArr=key;
    lockArr=lock;
    int spinCnt = 4;
    while(spinCnt--) {
        for(int i = -M+1;i<N;i++) {
            for(int j=-M+1;j<N;j++) {
                if(check(i,j)) {
                    return true;
                }
            }
        }
        
        spin();
    }
    
    return false;
}