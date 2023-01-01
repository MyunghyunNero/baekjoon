#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v;
    int sum=0;
    for(int i=0;i<k;i++){
        v.push_back(i+1);
        sum+=i+1;
    }
    if(sum>n){
        cout<< -1;
        return 0;
    }
    if((n-sum)%k==0){
        cout<<k-1;
    }else{
        cout<<k;
    }
    
}