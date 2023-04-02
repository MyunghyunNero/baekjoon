#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[1048577];
int b[1048577];
int n,k;
void merge(int s,int e){
    if ((e - s) > n / k) return;
    int mid=(s+e)/2;
    int i=s,j=mid+1,cnt=0;
    while(i<=mid && j<=e){
        if(a[i]<a[j]) b[cnt++]=a[i++];
        else b[cnt++]=a[j++];
    }
    while(i<=mid) b[cnt++]=a[i++];
    while(j<=e) b[cnt++]=a[j++];
    for(int i=s;i<=e;i++){
        a[i]=b[i-s];
    }
}
void mergeSort(int s,int e){
    if(s==e) return;
    int mid=(s+e)/2;
    mergeSort(s,mid);
    mergeSort(mid+1,e);
    merge(s,e);
}   
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>k;
    mergeSort(0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
}