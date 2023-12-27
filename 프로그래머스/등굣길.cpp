#include <string>
#include <vector>
#include <iostream>
using namespace std;
int arr[102][102];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(vector<int> v : puddles){
        arr[v[0]][v[1]] = -1;
    }
    arr[1][1]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]!=0) continue;
            if(arr[i-1][j] !=-1)
                arr[i][j]+=arr[i-1][j];
            if(arr[i][j-1]!=-1)
                arr[i][j]+=arr[i][j-1];
            arr[i][j]%=1000000007;
        }
    }

    return arr[m][n];
}