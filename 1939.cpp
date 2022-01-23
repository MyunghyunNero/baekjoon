#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int start,ed;
vector<pair<int,int>> v[100001];              
bool check[100001];               //섬방문했는지 체크
bool go(int x,int weight){             //weight란 값보다 가지고 갈 수 있는 무게가 더 크면 true반환
    if(check[x]){
        return false;
    }
    check[x]=true;
    if(x==ed){
        return true;
    }
    int len=v[x].size();
    for(int i=0;i<len;i++){
        int next=v[x][i].first;
        int cnt=v[x][i].second;
        if(cnt>=weight){
            if(go(next,weight)){
                return true;
            }
        }
    }
    return false;

}
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;  
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    cin >>start>>ed;
    int left=1;
    int right=1000000000;
    int ans=0;
    while(left<=right){                         //이분탐색
        int mid = left+(right-left)/2;
        memset(check,false,sizeof(check));
        if(go(start,mid)){
            ans=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    cout<<ans;

}
