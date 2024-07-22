#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> arrs;
int N;
long long ans;
void binarySearch(long long a, long long b) {
    while(a<=b){
        long long num = 0;
        long long mid = (a+b)/2;
        for(int arr : arrs) {
            num += mid/arr;
        }
        if(num<N) {
            a=mid+1;
        }else {
            b=mid-1;
        }
    }
    ans=a;
    
    
}
long long solution(int n, vector<int> times) {
    N = n;
    arrs = times;
    binarySearch(1,100000000000000);
    return ans;
}