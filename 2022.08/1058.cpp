#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
bool check[51];
int cnt;
vector<int> a[51];
void DFS(int len,int v){
    
    check[v] = true;
    if(len == 2) return ;
    
    for(int i=0; i<a[v].size(); i++){
        DFS(len+1, a[v][i]);   
    }
}

int main(){
    cin >> n;
    string s;
    for(int i=1; i<=n; i++){
        cin>>s;
        for(int j=0;j<n;j++){
            if(s[j]=='Y'){
                a[i].push_back(j+1);
            }
        }
    }

    for(int i=1; i<=n; i++){
        memset(check, false, sizeof(check));
        cnt = 0;
        DFS(0,i);
        for(int i=1; i<=n; i++){
            if(check[i] == true) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout<<ans-1;
    return 0;
}