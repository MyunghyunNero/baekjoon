#include <iostream>
#include <vector>
using namespace std;
int s,n;
vector<int> swit;
void man(int n){
    for(int i=n;i<=s;i+=n){
        if(swit[i]==1) swit[i]=0;
        else swit[i]=1;
    }
}
void women(int n){
    int diff=0;
    for(int i=1;i<=s/2;i++){
        if(n-i>=0 && n+i <=s){
            if(swit[n-i]!=swit[n+i]) break;
            diff=i;
        }
    }
    for(int i=n-diff;i<=n+diff;i++){
        if(swit[i]==1) swit[i]=0;
        else swit[i]=1;
    }
}
int main(){
    cin>>s;
    swit.push_back(-1);
    for(int i=0;i<s;i++){
        int a;
        cin>>a;
        swit.push_back(a);
    }
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(a==1) man(b);
        if(a==2) women(b);
    }
    for(int i=1;i<=s;i++){
        cout <<swit[i]<<' ';
        if(i%20==0) cout <<'\n';
    }
}