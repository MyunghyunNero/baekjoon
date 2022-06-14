#include <iostream>
using namespace std;
int main(){
    int x1,x2,y1,y2;
    int t;
    int x,y,r;
    int cnt=0;
    cin>>t;
    while(t--){
        cin>>x1>>y1>>x2>>y2;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
        cin >>x>>y>>r;
        int d1=(x-x1)*(x-x1)+(y-y1)*(y-y1);
        int d2=(x-x2)*(x-x2)+(y-y2)*(y-y2);
        if(d1<r*r&&d2<r*r){
            continue;
        }
        if(d1<r*r){
            cnt++;
            continue;
        }
        if(d2<r*r){
            cnt++;
            continue;
        }
        }
        cout<<cnt<<'\n';
        cnt=0;
    }
}