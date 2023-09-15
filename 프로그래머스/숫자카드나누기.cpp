#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int aCom=arrayA[0];
    int bCom=arrayB[0];
    for(int i=1;i<arrayA.size();i++){
        aCom=gcd(aCom,arrayA[i]);
        bCom=gcd(bCom,arrayB[i]);
    }
    bool Acheck=false;
    for(int i=0;i<arrayB.size();i++){
        if(arrayB[i]%aCom==0){
            Acheck=true;
        }
    }
    if(!Acheck ) answer=max(answer,aCom);
    bool Bcheck=false;
    for(int i =0;i< arrayA.size();i++){
        if(arrayA[i]%bCom==0){
            Bcheck=true;
        }
    }
    if(!Bcheck ) answer=max(answer,bCom);
                                   

    return answer;
}