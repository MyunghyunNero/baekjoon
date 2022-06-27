#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
int arr2[21][21];
bool check[21];
int mindiff=999999999;
void dfs(int num,int cnt){
    if(cnt==(n/2)){
        int start=0;
        int link=0;
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                if(check[i]==true&&check[k]==true){           //절반만 탐색하고 끝나므로 true인 값 절반을 start저장
                    start+=arr2[i][k];
                }
                if(check[i]==false&&check[k]==false){         //false인 값 절반을 link저장
                    link+=arr2[i][k];
                }
            }
        }
        int temp=abs(start-link);
        if(temp<mindiff){
            mindiff=temp;
        }
        return;
        
    }
    for(int i=num;i<n;i++){      //num부터 시작해야 (1,3),(3,1)같은 중복 값이 안생긴다. 어차피 1,3이라는 두 수가 같은 팀에 속한것만 알아야하기떄문에 중복제외
        if(!check[i]){
            check[i]=true;
            dfs(i+1,cnt+1);
            check[i]=false;
        }
    }
}
int main(){
    cin >>n;
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            cin>>arr2[i][k];
        }
    }
    dfs(0,0);
    cout<<mindiff;
}