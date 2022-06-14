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
        ord[i]=i;                 //순서 저장하는 배열
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
            if(d[ord[i]][ord[i+1]]==0){         // 값이 0이면 못가는 것이므로 false
                ok=false;
            }
            else{sum+=d[ord[i]][ord[i+1]];}
        }
        if(ok&&d[ord[n-1]][ord[0]]!=0){        //갈 수없는 배열은 더하지 말기
            sum+=d[ord[n-1]][ord[0]];
            if(ans>sum){
                ans=sum;
            }
        }
    }while(next_permutation(ord.begin(),ord.end())); //배열 순서 다 확인하기
    cout << ans;

}