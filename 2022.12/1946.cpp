#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int>> arr;
int t;
int main(){
    cin>>t;
   
    while(t--){
    	int ans=1;
        int n;
        cin>>n;
        arr.clear();
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            arr.push_back({a,b});
        }
        sort(arr.begin(),arr.end());
        int min =arr[0].second;
        for(int i=1;i<n;i++){
            if(arr[i].second<min) {
                ans++;
                min = arr[i].second;
            }
        }
        cout<<ans<<'\n';
    }
}