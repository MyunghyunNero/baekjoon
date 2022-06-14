#include <iostream>
#include <vector>
using namespace std;
int parent[101];
int find(int x){             //유니온 파인드
  if (x==parent[x]){
    return x;
  }
  else{
    int y = find(parent[x]);
    parent[x] = y;
    return y;
  }
}
void Union(int x,int y){
  x = find(x);
  y = find(y);
  parent[y] = x;
}
int main(){                      
    int n,m;
    int ans=0;
    cin >>n>>m;
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    while(m--){                       //쌍을 이루는 것들을 같은 그래프로
        int x,y;
        cin>>x>>y;
        Union(x,y);
    } 
    for(int i=2;i<=n;i++){             //1과 같은그래프면 값추가
        if(find(1)==find(i)){
            ans++;
        }
    }
    cout<<ans;
}