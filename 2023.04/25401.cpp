#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> v;
vector<int> dif;
int ans=9876543210;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int cnt=0;
            if((v[j]-v[i])%(j-i)==0){
                int diff=(v[j]-v[i])/(j-i);
                for(int k=0;k<n;k++){
                   if((v[i]+(k-i)*diff)!=v[k]){
                       cnt++;
                    }
                }
                ans=min(cnt,ans);
            }
            
        }

    }
    cout<<ans;
}   