#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,k;
int arr[101][100001];
int w[101];
int v[101];
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){         //매번 무게별로 최선을 고른다고 가정
            if(j>=w[i]){
                arr[i][j]=max(arr[i-1][j],arr[i-1][j-w[i]]+v[i]);        //현 배낭 선택 한것과 안 한 것중 큰 값 넣기 
            }
            else{
                arr[i][j]=arr[i-1][j];           //배낭 선택을 안했으므로 전에 값 가져오기
            }
        }
    }
    cout << arr[n][k];
    
}