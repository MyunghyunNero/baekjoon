#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int cnt;
int main(){
    int n;
    cin>>n;
    for(int i=64;i>=1;i=i/2){
        if(i>n){
            continue;
        }
        if(i==n){
            cnt++;
            break;
        }
        if(i<n){
            n=n-i;
            cnt++;
        }
    }
    cout<<cnt;

}