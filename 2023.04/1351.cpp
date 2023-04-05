#include <iostream>
#include <map>
using namespace std;
map<long,long> m;
long long n,p,q;
long long recur(long long a){
    if(m[a]!=0) return m[a]; //map 초기값 0 
    else
        return m[a] = recur(a/p)+recur(a/q);
}
int main(){
    cin>>n>>p>>q;
    m[0]=1;
    cout<< recur(n);
}