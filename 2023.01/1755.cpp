#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string arr[10] ={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main(){
    int a,b;
    cin>>a>>b;
    vector<pair<string,int>> v;
    for(int i=a;i<=b;i++){
        string s = to_string(i);
        string temp ="";
        for(int k=0;k<s.size();k++){
            int a = (s[k]-'0');
            temp+=arr[a];
        }
        v.push_back({temp,i});
    }
    sort(v.begin(),v.end());
    for(int i=a;i<=b;i++){
        if((i-a)!=0 && (i-a)%10==0){
            cout<<'\n';
        }
        cout<<v[i-a].second<<" ";
        
    }
}