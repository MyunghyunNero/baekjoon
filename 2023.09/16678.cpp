#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long sum;
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int score =0;
    for(int i : v){
        if(i<=score) continue;
        score++;
        if(score<i){
            sum+=i-score;
        }
    }
    cout<<sum;
}