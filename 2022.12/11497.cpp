#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int t;
    cin >>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(int i=0;i<n;i+=2){
            ans.push_back(v[i]);
        }
        int start=0;
        if(n%2==0){
            start=n-1;
        }else{
            start=n-2;
        }
        for(int i=start;i>=0;i-=2){
            ans.push_back(v[i]);
        }
        int answer=0;
        for(int i=0;i<n;i++){
            if(i==0){
                int m = max(abs(ans[0]-ans[1]),abs(ans[n-1]-ans[0]));
                if(answer<m) answer=m;
            }else if(i==n-1){
                int m = max(abs(ans[n-1]-ans[0]),abs(ans[n-1]-ans[n-2]));
                if(answer<m) answer=m;
            }else{
                int m =max(abs(ans[i]-ans[i-1]),abs(ans[i]-ans[i+1]));
                if(answer<m) answer=m;
            }
        }
        cout<<answer<<'\n';
    }

}
