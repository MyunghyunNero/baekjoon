#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int visited[13];
int answer;
bool possible(int row){
    for(int i=0;i<row;i++) {
        if(visited[i]==visited[row] || abs(visited[i]-visited[row])== row-i){
            return false;
        }
    }
    return true;
}
void dfs(int row, int n) {
    if(row == n){
        answer++;
        return;
    }
    for(int i=0;i<n;i++){
        visited[row]=i;
        if(possible(row)) {
            dfs(row+1,n);
        }
    }
}
int solution(int n) {
    dfs(0,n);
    return answer;
}