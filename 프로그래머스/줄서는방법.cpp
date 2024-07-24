#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
long long check[21];
bool arr[21];
vector<int> solution(int n, long long k) {
    vector<int> answer;
    check[0]=1;
    check[1]=1;
    for(int i=2;i<=20;i++) {
        check[i]=i*check[i-1];
    }
    int idx = n;
    while(idx) {
        int cnt = 0;
        long long start = k%check[idx-1]==0 ? k/check[idx-1]-1 : k/check[idx-1];
        k=k%check[idx-1]==0 ? check[idx-1] : k%check[idx-1];
        for(int i=1;i<=n;i++) {
            if(!arr[i]) {
                if(cnt==start) {
                    answer.push_back(i);
                    arr[i]=true;
                }
                cnt++;
            }
        }
        idx--;
    }
    for(int i=1;i<=n;i++) {
        if(!arr[i]) {
            answer.push_back(i);
        }
    }
    return answer;
}