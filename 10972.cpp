#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >>v[i];
    }
    bool ok=next_permutation(v.begin(),v.end());      //반환 값은 true 순열의 끝이면 false
    if(ok==false){                 
        cout << -1;
    }
    else{
        for(int i=0;i<n;i++){
            cout << v[i]<< ' ';
        }
    }
}