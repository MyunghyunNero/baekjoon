#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int cnt;
int arr[26];
int arr2[26];
int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n-1;i++){
        for(int k=i+1;k<n;k++){
            if(v[i].size()!=v[k].size()){
                continue;
            }
            bool check=false;
            memset(arr,-1,26*sizeof(int));
            memset(arr2,-1,26*sizeof(int));
            for(int j=0;j<v[i].size();j++){
                int alp1=v[i][j]-'a';
                int alp2=v[k][j]-'a';
                if(arr[alp1]==-1&&arr2[alp2]==-1){
                    arr[alp1]=alp2;
                    arr2[alp2]=alp1;
                }else if(arr[alp1]!=alp2){
                    check=true;
                }
            }
            if(check==false){
                cnt++;
            }
        }
    }

    cout<<cnt;
}