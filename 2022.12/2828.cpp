#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m,j;
    cin>>n>>m>>j;
    vector<int> v;
    int x=1;
    int ans=0;
    for(int i=0;i<j;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<j;i++){
        if(x+m-1<v[i]){
            x=v[i]-x-m+1;
            ans+=x;
        }else if(x>v[i]){
            x=v[i];
            ans+=x-v[i];
        }
    }
    cout<<ans;
}