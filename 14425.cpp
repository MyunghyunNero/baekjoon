#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

vector<string> v;
int main(){
    set<string> s;
    int n,m;
    cin >> n >> m ;
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        s.insert(str);
    }
    int cnt=0;
    for(int i=0;i<m;i++){
        cin>>str;
        if(s.find(str)!=s.end()){
            cnt++;
        }
    }
    cout <<cnt;
}