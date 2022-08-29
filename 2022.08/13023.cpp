#include <iostream>
#include <vector>
using namespace std;
int cnt=-1;
int n,m;
bool check[2001];
vector<int> arr[2001];
void dfs(int next,int c){
    if(c==5){
        cnt=c;
        return;
    }
    for(int i=0;i<arr[next].size();i++){
        if(check[arr[next][i]]) continue;
        check[arr[next][i]]=true;
        dfs(arr[next][i],c+1);
        check[arr[next][i]]=false;
    }
}
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(cnt>=5){
            break;
        }
        check[i]=true;
        dfs(i,1);
        check[i]=false;
    }
    if(cnt>=5){
        cout<<1;
    }else{
        cout<<0;
    }
}