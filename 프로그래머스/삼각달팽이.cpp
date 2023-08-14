#include <string>
#include <vector>
using namespace std;
int arr[1002][1002];
int number;
void dfs(int num,int r,int c,int size){
    if(arr[r][c]!=0||size<=0){
        return;
    }
    for(int i=0;i<size;i++){
        arr[r][c]=num++;
        r+=1;
    }
    r--;
    for(int i=0;i<size-1;i++){
        c+=1;
        arr[r][c]=num++;
    }
    for(int i=1;i<size-1;i++){
        r-=1;
        c-=1;
        arr[r][c]=num++;
    }
    dfs(num,r+1,c,size-3);
}
vector<int> solution(int n) {
    vector<int> answer;
    dfs(1,0,0,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            answer.push_back(arr[i][j]);
        }
    }
    return answer;
}