#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int arr[100001];
bool search(int index){
    int start=0;
    int end=n-1;
    int mid;
    while(end>=start){
        mid=(end+start)/2;
        if(arr[mid]==index){
            return true;
        }else if(arr[mid]>index){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return false;
}   
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin >>arr[i];
    }
    sort(arr,arr+n);
    cin>>m;
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        if(search(t)){
            cout << 1 <<'\n';
        }else{
            cout << 0 <<'\n';
        }
    }
}