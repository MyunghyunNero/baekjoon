#include <iostream>
#include <vector>
using namespace std;
int n;
int index=20001;
int ans;
int main(){
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int len= v.size();
    index=v[len-1];
    for(int i=len-2;i>=0;i--){
        if(index>v[i]){
            index= v[i];
        }else{
            ans += v[i]-index+1;
            index = index-1; 
        }
    }
    cout<<ans;

}