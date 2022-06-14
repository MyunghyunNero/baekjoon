#include <iostream>
using namespace std;
int parent[1000001];
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
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n ,m;
    cin >>n>>m;
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    while(m--){                     
        int input,a ,b;
        cin >>input>>a>>b;
        if(input ==0){              //0이면 합쳐준다
            Union(a,b);
        }
        if(input==1){
            if(find(a)==find(b)){                 //루트노드가 같으면 같은 집합이므로 YES
                cout <<"YES" <<'\n';
            }
            else{                                  //아니면 NO
                cout << "NO" << '\n'; 
            }
        }
    }

}