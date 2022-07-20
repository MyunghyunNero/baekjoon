#include <iostream>
using namespace std;
int arr[130][130];
int paper=0;
int n;
int cntblue;
int cntwhite;
bool check(int a,int b,int n){
    paper=arr[a][b];
    for(int i=a;i<a+n;i++){
        for(int k=b;k<b+n;k++){
            if(paper!=arr[i][k]){
                return false;
            }
        }
    }
    return true;
}
void divide(int a,int b,int n){
    if(check(a,b,n)){
        if(paper==1){
            cntblue++;
        }
        else if(paper==0){
            cntwhite++;
        }
        return;
    }
    divide(a,b,n/2);
    divide(a,b+n/2,n/2);
    divide(a+n/2,b,n/2);
    divide(a+n/2,b+n/2,n/2);

}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            cin>>arr[i][k];
        }
    }
    divide(1,1,n);
    cout <<cntwhite<<'\n';
    cout <<cntblue<<'\n';
}