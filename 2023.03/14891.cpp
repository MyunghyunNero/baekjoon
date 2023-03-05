#include <iostream>
#include <deque>
#include <string>
using namespace std;
deque<int> q[4];
void spin(int a,int spin){
    if(spin==1){
        int tmp=q[a].back();
        q[a].pop_back();
        q[a].push_front(tmp);
    }else if(spin==-1){
        int tmp=q[a].front();
        q[a].pop_front();
        q[a].push_back(tmp);
    }
}
int main(){
    for(int i=0;i<4;i++){
        string s;
        cin>>s;
        for(int j=0;j<8;j++){
            q[i].push_back(s[j]-'0');
        }
    }
    int n;
    cin>>n;
    for(int k=0;k<n;k++){
        int a,b;
        cin>>a>>b;
        a-=1;
        int left=q[a][6];
        int right=q[a][2];
        spin(a,b);
        int direct=-b;
        for(int i=a-1;i>=0;i--){
            if(q[i][2]!=left){
                left=q[i][6];
                spin(i,direct);
                direct=-direct;
            }else{
                break;
            }
        }
        direct=-b;
        for(int i=a+1;i<4;i++){
            if(q[i][6]!=right){
                right=q[i][2];
                spin(i,direct);
                direct=-direct;
            }else{
                break;
            }
        }
    }
    int sum=0;
    int score=1;
    for(int i=0;i<4;i++){
        if(q[i][0]==1){
            sum+=score;
        }
        score*=2;
    }
    cout<<sum;
}
