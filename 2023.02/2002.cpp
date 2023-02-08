#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
int n;
int ans;
int main(){
    map<string,int> m;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        m.insert({s,i});
    }
    vector<int> v;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(m[s]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(v[i]>v[j]) {
                ans++;
                break;
            }
        }
    }
    cout<<ans;
}