#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const pair<int,int> &p,const pair<int,int> &p2){
    if(p.second==p2.second)
        return p.first < p2.first;
    return p.second<p2.second;
}
int main(){
    vector<pair<int,int>> v;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end(),cmp);
    int min =v[0].second;
    int cnt=1;
    for(int i=1;i<n;i++){
        if(min<=v[i].first){
            cnt++;
            min=v[i].second;
        }
    }
    cout<<cnt;

    return 0;

}

