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
    int index;
    for(int i=0;i<j;i++){
        if(x+m-1<v[i]){
            index=v[i]-x-m+1;
            x=v[i]-m+1;
            ans+=index;
        }else if(x>v[i]){
        	index=x-v[i];
            x=v[i];
            ans+=index;
        }else if(x<=v[i]&&x+m-1>=v[i]){
        	continue;
        }
    }
    cout<<ans;
}