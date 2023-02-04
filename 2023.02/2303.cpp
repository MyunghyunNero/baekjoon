#include <iostream>
#include <vector>
using namespace std;
int maxOne(vector<int> &v1){
    int value =0;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            for(int k=j+1;k<5;k++){
                value=max(value,(v1[i]+v1[j]+v1[k])%10);
            }
        }
    }
    return value;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        vector<int> arr;
        for(int j=0;j<5;j++){
            int c;
            cin>>c;
            arr.push_back(c);
        }
        v.push_back(arr);
    }
    int min=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(min<=maxOne(v[i])){
            min=maxOne(v[i]);
            ans=i+1;
        }
    }
    cout<<ans;
}