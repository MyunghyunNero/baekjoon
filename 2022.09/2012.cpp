#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[500001];
long long sum;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        sum+=(abs(arr[i]-(i+1)));
    }
    cout<<sum;

}