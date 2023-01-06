#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> v;
    int cnt=1;
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            v.push_back(cnt);
            cnt = 1;
        }else{
            cnt++;
        }
    }
    v.push_back(cnt);
    int len = v.size();
    int ans=9999999;
    if(len%2 == 0){
        int value=0;
        for(int i=1;i<len-1;i+=2){
            value+=v[i];
        }
        ans = min(value,ans);
        value=0;
        for(int i=len-2;i>0;i-=2){
            value+=v[i];
        }
        ans = min(value,ans);
    }else{
        int value = 0;
        for(int i=0;i<len-1;i+=2){
            value+=v[i];
        }
        ans = min(value,ans);
        value = 0;
        for(int i=len-1;i>0;i-=2){
            value+=v[i];
        }
        ans = min(value,ans);
        value =0;
        for(int i=1;i<len-1;i+=2){
            value += v[i];
        }
        ans = min(value,ans);
    }
    cout<<ans;

}