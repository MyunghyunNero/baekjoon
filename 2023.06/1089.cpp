#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
string s[10];
string arr[5];
vector<long double> v[10];
int n;
long double ans;
int main(){
    s[0]="####.##.##.####";
    s[1]="..#..#..#..#..#";
    s[2]="###..#####..###";
    s[3]="###..####..####";
    s[4]="#.##.####..#..#";
    s[5]="####..###..####";
    s[6]="####..####.####";
    s[7]="###..#..#..#..#";
    s[8]="####.#####.####";
    s[9]="####.####..####";
    cin>>n;
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        int start=4*i;
        int e=3+4*i;
        for(int j=0;j<=9;j++){
            bool check=true;
            for(int k=0;k<5;k++){   
                for(int t=start;t<e;t++){
                    if(s[j][k*3+(t-start)]=='.' && arr[k][t]=='#'){
                        check=false;
                        break;
                    }
                }
                if(!check) break;
            }
            if(check){
                v[i].push_back((long double)j);
            }
        }
    }
    bool check2=true;
    for(int i=0;i<n;i++){
        if(v[i].empty()){
            check2=false;
            break;
        }else{
            long double sum=0;
            int dig=pow(10,n-1-i);
            for(int j=0;j<v[i].size();j++){
                sum+=v[i][j];
            }
            sum=(sum/v[i].size())*dig;
            ans+=sum;
        }
    }
    if(check2){
        cout<<ans;
    }else{
        cout<<-1;
    }
    
}   