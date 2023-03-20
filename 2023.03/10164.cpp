#include <iostream>
using namespace std;

long long combi(int a,int b){
    long long sum=1;
    int ma=a+b;
    int j=1;
    for(int i=a+1;i<=ma;i++){
        sum*=i;
        while(j<=b && (sum%j==0)){
            sum/=j++;
        }
    }
    sum = sum == 0 ? 1 : sum;
    return sum;
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    long long ans=0;
    k=k==0?0:k-1;
    int x=k/m; 
    int y=k%m;
    ans=combi(x,y) * combi(n-1-x,m-1-y);
    cout<<ans;
    
}