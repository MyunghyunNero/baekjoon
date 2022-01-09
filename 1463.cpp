#include <iostream>
#include <vector>
using namespace std;
vector<int> d;
int main(){
    int n;
    cin >> n;
    for(int i=0; i<=n;i++){
        d.push_back(i-1);
    }
    for(int i=2;i<=n;i++){
        d[i]=d[i-1]+1;
        if((i%3)==0&&d[i]>d[i/3]+1){
            d[i]=d[i/3]+1;
        }
        if((i%2)==0 && d[i]>d[i/2]+1){
            d[i]=d[i/2]+1;
        }
    }
    cout << d[n];
}