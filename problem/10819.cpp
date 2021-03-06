#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector> 
using namespace std;
int calculate(vector<int>& a){         //값 계산하기
    int sum=0;
    for(int i=1;i<a.size();i++){
        sum+=abs(a[i]-a[i-1]);
    }
    return sum;
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    sort(a.begin(),a.end());
    int ans=0;
    do{
        int temp=calculate(a);
        ans=max(ans,temp);
    }while(next_permutation(a.begin(),a.end()));              //모든 순열 돌아보기
    cout <<ans;
    return 0;
}