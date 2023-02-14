#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<pair<int,int>> c;
vector<pair<int,int>> h;
vector<pair<int,int>> v;
int ans=999999999;
int calDistance(){
    int sum=0;
    for(int i=0;i<h.size();i++){
        int d=9999999;
        int x=h[i].first;
        int y=h[i].second;
        for(int j=0;j<v.size();j++){
            d=min(d,abs(x-v[j].first)+abs(y-v[j].second));
        }
        sum+=d;
    }
    return sum;
}
void selectC(int cnt,int idx){
    if(cnt==m){
        ans=min(ans,calDistance());
        return;
    }
    for(int i=idx;i<c.size();i++){
        v.push_back({c[i].first,c[i].second});
        selectC(cnt+1,i+1);
        v.pop_back();
    }
}
int main(){
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int a;
            cin>>a;
            if(a==1){
                h.push_back({i,j});
            }else if(a==2){
                c.push_back({i,j});
            }
        }
    }
    selectC(0,0);
    cout<<ans;
    

}