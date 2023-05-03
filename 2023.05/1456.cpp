#include <iostream>
#include <vector>
using namespace std;
bool check[10000001];
vector<long long> v;
void arito(){
    check[1]=true;
    for(long long i=2;i<=10000000;i++){
        if(!check[i]){
            v.push_back(i);
            for(long long j=i+i;j<=10000000;j+=i){
                check[j]=true;
            }
        }
    }
}
long long cnt;
int main(){
    long long s,e;
    cin>>s>>e;
    arito();
    for(long long i=0;i<v.size();i++){
            long long a=v[i];
            long long cur=v[i];
            while(cur<=e/a){
                cur*=a;
                if(cur>=s) cnt++;
            }
    
    }
    cout<<cnt;
}