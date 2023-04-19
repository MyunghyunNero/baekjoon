#include <iostream>
#include <vector>
using namespace std;
int ans[101][101];
vector<int> v[101];
bool check[101][101];
int n;
void search(int s,int e){
    for(int i=0;i<v[e].size();i++){
        if(ans[s][v[e][i]]) continue;
        ans[s][v[e][i]]=1;
        search(s,v[e][i]);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            if(a==1) v[i].push_back(j);
        }
    }
    for(int i=0;i<n;i++){
        search(i,i);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }
}