#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){            //최소값은 오름차순이고 개인시간을 다 더한값
    int n;
    cin >> n;
    vector<int> p;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        p.push_back(a);
    }
    sort(p.begin(),p.end());  //오름차순 정렬
    int sum=0;
    int t=0;              
    for(int i=0;i<n;i++){
        t+=p[i];               //t는 개인 마다 기다리는 시간
        sum+=t;             //총합
    }
    cout << sum;
} 