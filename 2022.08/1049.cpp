#include <iostream>
#include <vector>
using namespace std;
int n,m;
int minsix=9999999;
int minone=9999999;
int sum;
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(minsix>a){
            minsix=a;
        }
        if(minone>b){
            minone=b;
        }
    }
    if(minsix>(minone*6)){
        sum=minone*n;
    }else if(minsix<minone*(n%6)){
        sum=minsix*(n/6+1);
    }else{
        sum=minsix*(n/6)+minone*(n%6);
    }
    cout<<sum;
}