#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int>> v;
int d[101];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    int dmax=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[i].second>v[j].second &&d[i]<d[j]+1){
                d[i]=d[j]+1;
            }
        }
        if(d[i]>dmax){
            dmax=d[i];
        }
    }
    cout<<n-(dmax+1);     //1을 더하는 것은 d[i]의 초기값을 0으로 설정했기 때문 
}