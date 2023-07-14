#include <iostream>
#include <vector>
using namespace std;
int n;
long long ans;
vector<int> dice[10001];
int diceup(int i){
    int up=0;
    if(i==0 ){
        up=5;
    }else if(i==1){
        up=3;
    }else if(i==2){
        up=4;
    }else if(i==3){
        up=1;
    }else if(i==4){
        up=2;
    }else if(i==5){
        up=0;
    }
    return up;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            int a;
            cin>>a;
            dice[i].push_back(a);
        }
    }
    for(int i=0;i<6;i++){
        long long sum=0;
        int down=i;
        int up=diceup(down);
        int cnt=0;
        for(int k=0;k<6;k++){
            if(k==up || k==down) continue;
            cnt=max(cnt,dice[0][k]);
        }
        sum+=cnt;
        for(int j=1;j<n;j++){
            int cnt=0;
            for(int k=0;k<6;k++){
                if(dice[j-1][up]==dice[j][k]){
                    down=k;
                    up=diceup(down);
                    break;
                }
            }
            for(int k=0;k<6;k++){
                if(k==up || k==down) continue;
                cnt=max(cnt,dice[j][k]);
            }
            sum+=cnt;
        }
        ans=max(ans,sum);
    }
    cout<<ans;
}