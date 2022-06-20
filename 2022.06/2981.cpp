#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int a, int b){
    if(a%b==0){
        return b;
    }
    return gcd(b,a%b);
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> ans;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int m=v[1]-v[0];
    for(int i=2;i<n;i++){
        m=gcd(m,v[i]-v[i-1]);         //v[i]-v[i-1]=m*(몫[i]-몫[i-1])+(r-r)   ---두 나머지가 같은 m을 구하는 과정
    }
    for(int i=1;i*i<=m;i++){       //최대 공약수 m에서 나누어떨어지는 모든 값 구하기
        if(m%i==0){
            ans.push_back(i);
            if(i!=m/i){
                ans.push_back(m/i);
            }
        }
    }
    sort(ans.begin(),ans.end());
    int end=ans.size();
    for(int i=0;i<end;i++){
        if(ans[i]!=1){
            cout<<ans[i]<<' ';
        }
    }

}