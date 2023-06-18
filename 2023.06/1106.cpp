#include <iostream>
using namespace std;
int d[100001];
int c,n;
int main(){
    cin>>c>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        for(int j=1;j<=100001;j++){
            if(j-a>=0){
                d[j]=max(d[j],d[j-a]+b);
            }
        }
    }
    for(int i=1;i<=100001;i++){
        if(d[i]>=c){
            cout<<i;
            break;
        }
    }
}