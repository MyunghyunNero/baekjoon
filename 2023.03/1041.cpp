#include <iostream>
using namespace std;
int dice[6]; //{아래,동,남,북,서,위}
int n;
long long mintwo=1000000;
long long minthree=1000000;
void minThree(){
    for(int i=0;i<6;i++){
        int temp=dice[i];
        for(int j=0;j<6;j++){
            if(i==j || j==5-i) continue;
            for(int k=0;k<6;k++){
                if(k==i||k==j||k==5-i||k==5-j) continue;
                if(minthree>temp+dice[j]+dice[k]) minthree =temp+dice[j]+dice[k];
            }
        }
    }
}
void minTwo(){
    for(int i=0;i<6;i++){
        int temp=dice[i];
        for(int j=0;j<6;j++){
            if(i==j||j==5-i) continue;
            if(mintwo>temp+dice[j]) mintwo=temp+dice[j];
        }
    }
}
long long minone=1000000;
int sum;
int maxv;
int main(){
    cin>>n;
    for(int i=0;i<6;i++){
        cin>>dice[i];
        if(minone>dice[i]) minone=dice[i];
        sum+=dice[i];
        maxv=max(maxv,dice[i]);
    }
    if(n==1){
        cout<<sum-maxv;
    }else{
        minTwo();
        minThree();
        long long answer=0;
        answer += minthree * 4;
		answer += mintwo * (4 * (n - 2) + 4 * (n - 1));
		answer += minone * (4 * (n - 1)*(n - 2) + (n - 2)*(n - 2));
        cout<<answer;
    }
}