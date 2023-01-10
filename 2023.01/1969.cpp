#include <iostream>
#include <string>
#include <vector>
using namespace std;
char dna[4]={'A','C','G','T'};
int main(){
    int n,m;
    cin>>n>>m;
    vector<string> v;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    string ans="";
    int sum=0;
    for(int i=0;i<m;i++){
        int cnt[4]={0,0,0,0};
        int maxCnt=0;
        int index;
        for(int k=0;k<n;k++){
            for(int j=0;j<4;j++){
                if(v[k][i]==dna[j]){
                    cnt[j]++;
                }
            }
        }
        for(int k=0;k<4;k++){
            if(cnt[k]>maxCnt){
                maxCnt=cnt[k];
                index=k;
            }
        }
        sum+=(n-maxCnt);
        ans+=dna[index];
    }
    cout<<ans<<'\n'<<sum;

}