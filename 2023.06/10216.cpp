#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int t;
int d[3001];
int findx(int x){
    if(x==d[x]){
        return x;
    }else{
        int y=findx(d[x]);
        d[x]=y;
        return y;
    }
}
void unio(int x,int y){
    int px=findx(x);
    int py=findx(y);
    d[py]=px;
}
int calsqr(int x1,int y1,int x2,int y2){
    return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
bool belong(int x1,int y1,int x2,int y2,int r1,int r2){
    if(calsqr(x1,y1,x2,y2)<=(r1+r2)*(r1+r2)){
        return true;
    }else{
        return false;
    }
}
int main(){
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<=3000;i++){
            d[i]=i;
        }
        int ans=n;
        vector<pair<pair<int,int>,int>> v;
        for(int i=0;i<n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            v.push_back({{a,b},c});
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(findx(i)==findx(j)) continue;
                if(belong(v[i].first.first,v[i].first.second,v[j].first.first,v[j].first.second,v[i].second,v[j].second)){
                    unio(i,j);
                    ans--;
                }
            }
        }
        cout<<ans<<'\n';
    }
}