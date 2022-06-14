#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long fac[21];
bool check[21];
long long factorial(int n){             //n의 팩토리얼 저장
    if(n==1){
        fac[1]=1;
        return fac[1];
    }
    fac[n]=n*factorial(n-1);
    return fac[n];
}
int main(){
    int n,num;
    cin >>n>>num;
    factorial(n);
    fac[0]=1;
    vector<int> v(n); 
    if(num==1){                      //1을 누를떄
        long long k;
        cin>>k;
        for(int i=0;i<n;i++){
            for(int j=1;j<=n;j++){  
                if(check[j]==true){                // j 값이 이미 사용되었으면 넘어감
                    continue;
                }
                if(k>fac[n-i-1]){                 //k번이 i번쨰 수열 수 찾을 떄 그 다음 수부터 수열의 수를 빼준다.
                    k-=fac[n-i-1];
                }
                else{
                    v[i]=j;
                    check[j]=true;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++){
            cout << v[i]<< ' ';
        }
    }
    else if(num==2){        //2번 누를때
        long long cnt=1;
        for(int i=0;i<n;i++){
            cin >>v[i];
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<v[i];j++){     //배열값보다 작으면
                if(check[j]==false){     //원소가 사용 안되었으면
                    cnt+=fac[n-i-1];      // 그 다음 배열 원소 순열 수만큼 더함
                }
            }
            check[v[i]]=true;           //그 원소 이미 사용했으니 true저장
        }
        cout << cnt;
    }

}

