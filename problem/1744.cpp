#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int zero=0;
    int one=0;
    vector<int> plus;
    vector<int> minus;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a==1){
            one+=1;
        }else if(a>0){
            plus.push_back(a);
        }else if(a<0){
            minus.push_back(a);
        }else{
            zero+=1;
        }
    }
    sort(plus.begin(),plus.end());
    reverse(plus.begin(),plus.end());
    sort(minus.begin(),minus.end());
    int sum=0;
    if(plus.size()%2==1){ //홀수면은 두개씩 묶을 때 하나가 남음
        plus.push_back(1);     // plus배열은 두 숫자를 쌍으로 곱하면서 계산 할거기 때문에 1을 넣음으로서 해결
    }
    if(minus.size()%2==1){   //홀수면 두개씩 묶을 때 하나 남음
        minus.push_back(zero>0?0:1); //하나 남은게 음수면 0이랑 곱하는게 이득이기 때문에 0존재 유무 체크
    }
    sum=one; //1은 무조건 더하는게 이득이므로 더함
    for(int i=0;i<plus.size();i+=2){      //이제 두 쌍씩 곱해주기
        sum+=(plus[i]*plus[i+1]);
    }
    for(int i=0;i<minus.size();i+=2){
        sum+=(minus[i]*minus[i+1]);
    }
    cout << sum;


}