#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
long long ans;
int student[2000001];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        student[a]++;
    }
    for(int i=1;i<2000001;i++){
        long long cnt=0;
        for(int j=1;i*j<=2000001;j++){
            cnt+=student[i*j];
        }
        if(cnt<2) continue;
        ans=max(cnt*i,ans);
    }   
    cout<<ans;
}