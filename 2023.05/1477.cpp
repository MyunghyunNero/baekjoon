#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,l,ans=1000;
vector<int> rest;
int main(){
    cin>>n>>m>>l;
    rest.push_back(0);
    rest.push_back(l);
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        rest.push_back(temp);
    }
    sort(rest.begin(),rest.end());
    int start=1;
    int end=l-1;
    while(start<=end){
        int mid= (start+end)/2;
        int v=0;
        for(int i=1;i<rest.size();i++){
            int d= rest[i]-rest[i-1];
            int cnt=d/mid;
            if(cnt>0){
                if(d%mid==0) v+=cnt-1;
                else v+=cnt;
            }
        }
        if(v>m){
            start=mid+1;
        }else{
            end=mid-1;
            ans=min(ans,mid);
        }
    }
    cout<<ans;
    
}