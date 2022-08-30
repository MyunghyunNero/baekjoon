#include <iostream>
#include <vector>
using namespace std;
int n,k;
int cnt;
vector<int> arr;
void search(int n){
    if(n==0) return;
    int i;
    for(i=1;i<n;i*=2){
    }
    arr.push_back(i/2);
    search(n-(i/2));
}
int main(){
    cin>>n>>k;
    search(n);
    int len=arr.size();
    while(len>k){
        cnt+=(arr[len-2]-arr[len-1]);
        arr[len-2]*=2;
        arr.pop_back();
        len=len-1;
    }
    cout<<cnt;
}   