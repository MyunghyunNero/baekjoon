#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
string s;
int maxValue;
int n;
map<pair<string,int>,bool> visited;
void dfs(int change){
    
    if(change == n ){
        maxValue = max(maxValue , stoi(s));
        return;
    }
    for(int i = 0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
            swap(s[i], s[j]);
            if(!visited[{s,change}]){
                dfs(change + 1);
                visited[{s,change}]=true;
            }
            swap(s[i], s[j]);
        }
    }
}
int main(){
    int t = 1;
    int testCase;
    cin>>testCase;
    while(t<=testCase){
        visited.clear();
        maxValue = 0;
        cin>>s>>n;
        dfs(0);
        cout<<'#'<<t<<' '<<maxValue<<'\n';
        t++;
    }
}