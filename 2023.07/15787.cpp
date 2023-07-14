#include <iostream>
#include <set>
#include <string>
using namespace std;
set<int> st;
int n,m;
int arr[100002];
int getOne(int num,int x){
    num|= 1<<x;
    return num;
}
int getTwo(int num,int x){
    return num & ~(1<<x);
}
int getThree(int num){
    num<<=1;
    num &= ((1<<21) -1);
    return num;
}
int getFour(int num){
    num>>=1;
    num&=~1;
    return num;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b;
        if(a==1){
            cin>>c;
            arr[b]=getOne(arr[b],c);
        }else if(a==2){
            cin>>c;
            arr[b]=getTwo(arr[b],c);
        }else if(a==3){
            arr[b]=getThree(arr[b]);
        }else{
            arr[b]=getFour(arr[b]);
        }
    }
    for(int i=1;i<=n;i++){
        st.insert(arr[i]);
    }
    cout<<st.size();

}