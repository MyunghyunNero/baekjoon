#include <iostream>
#include <set>
using namespace std;
int main(){
    int n,m;
    int t;
    set<int>::iterator iter;
    set<int> s1;
    set<int> s2;
    int cnt=0;
    cin >>n >>m;
    for(int i=0;i<n;i++){
        cin>>t;
        s1.insert(t);
    }
    for(int i=0;i<m;i++){
        cin >>t;
        s2.insert(t);
        if(s1.find(t)!=s1.end()){
            cnt++;
        }
    }
    for(iter=s1.begin();iter!=s1.end();iter++){
        if(s2.find(*iter)!=s2.end()){
            cnt++;
        }
    }
    cout <<n+m-cnt;
}