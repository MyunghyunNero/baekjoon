#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int parent[500000];
int ans;

int find(int x){
  if (x==parent[x]){
    return x;
  }
  else{
    int y = find(parent[x]);
    parent[x] = y;
    return y;
  }
}

bool unionfunc(int x,int y){
  x = find(x);
  y = find(y);
  if(x==y){return true;}
  else{
    parent[x] = y;
    return false;
  }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int u, v;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // Union Find
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        if (unionfunc(u, v))
        {
            ans = i;
            break;
        }
    }
    if (ans == 0) cout << 0;
    else cout << ans;
}