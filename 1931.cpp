#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const pair<int,int> &p,const pair<int,int> &p2){    //회의 마감시간 기준으로 정렬
    if(p.second==p2.second)
        return p.first < p2.first;
    return p.second<p2.second;
}
int main(){
    vector<pair<int,int>> v;       //회의 시간과 마감시간 저장
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
        if(min<=v[i].first){ //회의 시간이 전 회의 마감보다 같거나 길어야함
            cnt++;
            min=v[i].second;
        }
    }
    cout<<cnt;

    return 0;

}

