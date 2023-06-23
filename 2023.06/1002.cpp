#include <iostream>
#include <cmath>
using namespace std;
int t;
int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        int x1,y1,r1,x2,y2,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        double len= (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
        int c1=(r2-r1)*(r2-r1);
        int c2=(r1+r2)*(r1+r2);
        if(len==0){
            if(r1==0 && r2==0){
                cout<<1<<'\n';
            }
            else if(c1==0){
                cout<<-1<<'\n';
            }else{
                cout<<0<<'\n';
            }
        }else if(c1<len && c2>len){
            cout<<2<<'\n';
        }else if(len == c2  || len==c1){
            cout<<1<<'\n';
        }
        else{
            cout<<0<<'\n';
        }
        
    }
}