#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t,n;
int main(){
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            arr.push_back(a);

        }
        int len= arr.size();
        long long ans=0;
        int cnt=0;
        int maxValue=-1;
        for(int i=len-1;i>=0;i--){
            maxValue = max(arr[i],maxValue);
            ans += maxValue-arr[i];
        }
        cout<<ans<<'\n';
    }
    
}