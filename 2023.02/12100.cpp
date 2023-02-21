#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;
int ans; 
int getMax(vector<vector<int>> arr)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res = max(res, arr[i][j]);
        }
    }
    return res;
}
vector<int> merge(vector<int> v){
    int len=v.size();
    vector<int> m;
    queue<int> q;
    for(int i=0;i<len;i++){
        if(q.empty()){
            q.push(v[i]);
        }else{
            if(q.front()==v[i]){
                m.push_back(v[i]+v[i]);
                q.pop();
            }else{
                m.push_back(q.front());
                q.pop();
                q.push(v[i]);
            }
        }
    }
    if(!q.empty()){
        m.push_back(q.front());
    }
    return m;
}
vector<vector<int>> upMove(vector<vector<int>> arr){
    for(int j=0;j<n;j++){
        vector<int> v;
        for(int i=0;i<n;i++){
            if(arr[i][j]!=0){
                v.push_back(arr[i][j]);
            }
        }
        vector<int> m = merge(v);
        for(int i=0;i<n;i++){
            if(i<m.size()){
                arr[i][j]=m[i];
            }else{
                arr[i][j]=0;
            }
        }
    }
    return arr;
}
vector<vector<int>> downMove(vector<vector<int>> arr){
    for(int j=0;j<n;j++){
        vector<int> v;
        for(int i=n-1;i>=0;i--){
            if(arr[i][j]!=0){
                v.push_back(arr[i][j]);
            }
        }
        vector<int> m = merge(v);
        for(int i=n-1;i>=0;i--){
            if(n-i<=m.size()){
                arr[i][j]=m[n-i-1];
            }else{
                arr[i][j]=0;
            }
        }
    }
    return arr;
}
vector<vector<int>> rightMove(vector<vector<int>> arr){
    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=n-1;j>=0;j--){
            if(arr[i][j]!=0){
                v.push_back(arr[i][j]);
            }
        }
        vector<int> m = merge(v);
        for(int j=n-1;j>=0;j--){
            if(n-j<=m.size()){
                arr[i][j]=m[n-j-1];
            }else{
                arr[i][j]=0;
            }
        }
    }
    return arr;
}
vector<vector<int>> leftMove(vector<vector<int>> arr){
    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0){
                v.push_back(arr[i][j]);
            }
        }
        vector<int> m = merge(v);
        for(int j=0;j<n;j++){
            if(j<m.size()){
                arr[i][j]=m[j];
            }else{
                arr[i][j]=0;
            }
        }
    }
    return arr;
}

void dfs(int cnt, vector<vector<int>> arr)
{
    
    if (cnt == 5){
        ans = max(ans, getMax(arr));
        return;
    }
    dfs(cnt + 1, upMove(arr));
    dfs(cnt + 1, leftMove(arr));
    dfs(cnt + 1, rightMove(arr));
    dfs(cnt + 1, downMove(arr));
}
int main(){
    cin>>n;
    vector<vector<int>> map(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    dfs(0,map);
    cout<< ans;
}