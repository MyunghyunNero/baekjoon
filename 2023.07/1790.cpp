#include <iostream>
#include <cmath>
#include <string>
using namespace std;
long long n,k;
int ans;
long long calLength(int num){
    long long len=0;
    for(int start=1,i=1;start<=num;start*=10,i++){
        int end=start*10-1;
        if(end>num){
            end=num;
        }
        len+=(end-start+1)*i;
    }
    return len;
}
void binary_search(int left,int right){
    while(left<right){
        int mid=(left+right)/2;
        long long len=calLength(mid);
        if(len<k){
            left=mid+1;
        }else{
            right=mid;
            ans=right;
        }
    }
} 
int main(){
    cin>>n>>k;
    if(calLength(n)<k){
        cout<<-1;
        return 0;
    }
    ans=n;
    binary_search(1,n);
    string s=to_string(ans);
    cout<<s[s.size()-1-(calLength(ans)-k)];

}