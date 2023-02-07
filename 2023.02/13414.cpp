#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(const pair<string,int>& a, const pair<string,int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
int main(){
    int k,l;
    cin>>k>>l;
    map<string,int> m;
    for(int i=0;i<l;i++){
        string s;
        cin>>s;
        if(m.find(s)!=m.end()){
            m[s]=i;
        }else{
            m.insert({s,i});
        }
    }
    vector<pair<string,int>> vec( m.begin(), m.end() );
    sort(vec.begin(), vec.end(), cmp);

    //vec 사이즈가 뽑는인원보다 적을수 있음
    if(vec.size()<k){
        k=vec.size();
    }
    for(int i=0;i<k;i++){
        cout<<vec[i].first<<'\n';
    }
}