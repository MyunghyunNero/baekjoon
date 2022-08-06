#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int sum,en,start,minlen=99999999;
int n,s;
vector<int> v;
int main(){
    cin>>n>>s;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    while(start<=en){
        if(sum>=s){
            minlen=min(minlen,en-start);
            sum-=v[start++];
        }
        else if(en==n){
            break;
        }else{
            sum+=v[en++];
        }
    }
    if(minlen==99999999){
        cout<< 0;
    }else{
        cout <<minlen;
    }

}