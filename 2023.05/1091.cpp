#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n,cnt;
vector<int> s,p,v,temp;
bool isSorted()
{
    for (int i = 0; i < n; i++)
        if (v[i] != (i % 3))
            return false;

    return true;
}
set<vector<int>> visited;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        p.push_back(a);
        v.push_back(a);
    }
    visited.insert(v);
    temp.resize(n);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        s.push_back(a);
    }
    
    while(1){
        if(isSorted()){
            break;
        }
        for(int i=0;i<n;i++){
            temp[s[i]]=v[i];
        }
        for(int i=0;i<n;i++){
            v[i]=temp[i];
        }
        if(visited.find(v) == visited.end()){
            visited.insert(v);
        }else{
            cnt=-1;
            break;
        }
        cnt++;
    }
    cout<<cnt;
}