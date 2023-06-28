#include <iostream>
using namespace std;
long long w,h,f,c,x1,y1,x2,y2;
long long sum;
int main(){
    cin>>w>>h>>f>>c>>x1>>y1>>x2>>y2;
    sum+=(c+1)*(x2-x1)*(y2-y1);
    long long size=w*h;
    long long dup=min(f,w-f);
    if(x1>=dup){
        cout<<size-sum;
    }else if(x1<dup && x2 >dup){
        long long addSum=(c+1)*((dup-x1)*(y2-y1));
        cout<<size-(sum+addSum);
    }else{
        cout<<size-2*sum;
    }
}