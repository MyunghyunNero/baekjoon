#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,s;
int ans;
void check(vector<int>& v,int sum,int i){
    if(i==n){                            //배열의 끝을 도달했을 떄
        if(sum==s){                      //s와 합이 같으면 1증가
            ans++;
        }
        return;
    }
    check(v,sum+v[i],i+1);                //i번쨰 값을 더할때
    check(v,sum,i+1);                      //i번쨰 값을 안 더할때
}
int main(){
    cin>>n>>s;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    check(v,0,0);
    if(s==0){                        //s가 0이면 공집합은 빼야하므로 -1해준다
        cout<<ans-1;
    }
    else{
        cout<<ans;
    }
}