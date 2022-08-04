#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,x;
int cnt;
vector<int> v;
void search(int start,int end){
    if(start>=end){
        return;
    }
    if((v[start]+v[end])==x){
        cnt++;
        search(start+1,end-1);
    }else if((v[start]+v[end])>x){
        search(start,end-1);
    }else if((v[start]+v[end])<x){
        search(start+1,end);
    }
}
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    cin>>x;
    sort(v.begin(),v.end());
    search(0,n-1);
    cout <<cnt;
}