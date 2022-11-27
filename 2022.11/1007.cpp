#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int t,n;
bool visit[21];
vector<pair<int,int>> v;
double ans;
double vectorSum(){
    pair<int,int> sum = {0,0};
    for(int i=0;i<n;i++){
        if(visit[i]){
            sum.first -= v[i].first;
            sum.second -= v[i].second;
        }else{
            sum.first += v[i].first;
            sum.second += v[i].second;
        }
    }
    return sqrt(pow(sum.first,2)+pow(sum.second,2));
}
void selectPoint(int start,int cnt){
    if(cnt== n/2){
        ans = min(ans , vectorSum());
        return;
    }
    for(int i= start ; i<n;i++){
        visit[i]=true;
        selectPoint(i+1,cnt+1);
        visit[i]=false;
    }
}
int main(){
    cin >>t;
    cout << fixed;
	cout.precision(12);
    
    while(t--){
        cin >>n;
        ans=1008000000;
        memset(visit,0,sizeof(visit));
        v.clear();
        for(int i=0 ;i<n;i++){
            int a,b;
            cin>>a>>b;
            v.push_back({a,b});
        }
        selectPoint(0,0);
        cout<<ans<<'\n';
    }
}

