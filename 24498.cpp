#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>> n;
    vector<int> d(n);
    for(int i=0;i<n;i++){
        cin>> d[i];
    }
    int max=0;
    for(int i=0;i<n;i++){
        if(max<d[i]){
            max=d[i];
        }        
    }
    
    for(int i=1;i<n-1;i++){
        int tmp=0;
        if(d[i-1]>0&&d[i+1]>0&&d[i]>0){
            if(d[i-1]>d[i+1]){
                tmp=d[i+1];
            }
            else{
                tmp=d[i-1];
            }
            if(max<d[i]+tmp){
                max=d[i]+tmp;
            }
        }
    }
    cout<<max;
    

}