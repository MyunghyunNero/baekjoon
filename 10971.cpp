#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> d(n);
    vector<int> ord(n);
    for(int i=0;i<n;i++){
        ord[i]=i;
    }
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            int a;
            cin>> a;
            d[i].push_back(a);
        }
    }
    int ans=2147483647;
    do{
        bool ok=true;
        int sum=0;
        for(int i=0;i<n-1;i++){
            if(d[ord[i]][ord[i+1]]==0){
                ok=false;
            }
            else{sum+=d[ord[i]][ord[i+1]];}
        }
        if(ok&&d[ord[n-1]][ord[0]]!=0){
            sum+=d[ord[n-1]][ord[0]];
            if(ans>sum){
                ans=sum;
            }
        }
    }while(next_permutation(ord.begin(),ord.end()));
    cout << ans;

}