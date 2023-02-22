#include <iostream>
#include <vector>
using namespace std;
int parent[51];

int n,m;
int ans;
vector<vector<int>> v(51);
vector<int> know;
int find1(int x){
  if (x==parent[x]){
    return x;
  }
  else{
    int y = find1(parent[x]);
    parent[x] = y;
    return y;
  }
}
void union1(int x,int y){
  x = find1(x);
  y = find1(y);
  parent[y] = x;
}

int main(){
    cin>>n>>m;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a;
        cin>>a;
        know.push_back(a);
    }
    
    for (int i = 1; i <= n; i++) 
        parent[i] = i;
    for(int i=0;i<m;i++){
        int p;
        cin>>p;
        int num;
        cin>>num;
        v[i].push_back(num);
        for(int j=1;j<p;j++){
            int a;
            cin>>a;
            union1(a,num);
            num=a;
            v[i].push_back(num);
        }
    }
    int cnt=0;
    for(int i=0;i<m;i++){
        bool check=true;
        for(int j=0;j<v[i].size();j++){
            for(int k=0;k<t;k++){
                if( find1(know[k]) ==find1(v[i][j])){
                    cnt++;
                    check=false;
                    break;
                }
            }
            if(!check) break;
        }
    }
    cout<<m-cnt;

}
