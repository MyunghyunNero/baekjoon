#include <iostream>
using namespace std;
int n;
int arr[101];
int oper[4];
int minindex=1000000001;
int maxindex=-1000000001;
void dfs(int result,int cnt){      //백트래킹 이용
    if(n==cnt){
        if(result>maxindex){
            maxindex=result;
        }
        if(result<minindex){
            minindex=result;
        }
        return;
    }
    for(int i=0;i<4;i++){
        if(oper[i]!=0){
            oper[i]--; //연산자 수 제거
            if(i==0){
                dfs(result+arr[cnt],cnt+1);
            }
            if(i==1){
                dfs(result-arr[cnt],cnt+1);
            }
            if(i==2){
                dfs(result*arr[cnt],cnt+1);
            }
            if(i==3){
                dfs(result/arr[cnt],cnt+1);
            }
            oper[i]++;  //다른 계산값 구하기 위해 연산자 갯수 다시 추가해야함 
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<4;i++){
        cin>>oper[i];
    }
    dfs(arr[0],1);
    cout << maxindex<<'\n';
    cout<<minindex;

}