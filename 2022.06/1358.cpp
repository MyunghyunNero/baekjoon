#include <iostream>
using namespace std;
int main(){
    int w,h,x,y,p;
    int x1,y1;
    int cnt=0;
    cin>>w>>h>>x>>y>>p;
    while(p>0){
        p--;
        cin>>x1>>y1;
        if(x1>=x&&x1<=x+w&&y1>=y&&y1<=y+h){
            cnt++;
            continue;
        }
        int leftd1=(x-x1)*(x-x1)+(y+h/2-y1)*(y+h/2-y1);
        if(leftd1<=(h/2*h/2)){
            cnt++;
            continue;
        }
        int rightd1=(x+w-x1)*(x+w-x1)+(y+h/2-y1)*(y+h/2-y1);
        if(rightd1<=(h/2*h/2)){
            cnt++;
            continue;
        }
    }
    cout<<cnt;
}