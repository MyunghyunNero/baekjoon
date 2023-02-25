#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n,k;
string s;
vector<char> v;
int main(){
    iostream::sync_with_stdio(0);
	cin.tie(0);
    cin>>n>>k>>s;
    for(int i=0;i<n;i++){
        while(k!=0 && !v.empty() && v.back()<s[i]){
            v.pop_back();
            k--;
        }
        v.push_back(s[i]);
    }
    while(k--){
        v.pop_back();
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
}