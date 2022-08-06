#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt,high,low,sum;
int main() {
        int n;
        vector<bool> check;
        vector<int> prime;
        cin>>n;
        check.resize(n + 1, true);
        for (int i = 2; i * i <= n; i++) {
                if (check[i] == true) {
                        for(int j = i + i; j <= n; j += i)
                                check[j] = false;
                }
        }
        for (int i = 2; i < n + 1; i++) {
                if (check[i] == true) 
                        prime.push_back(i);
        }
        
        while (1) {
                if (sum >= n){
                        sum -= prime[low++];
                }else if (high == prime.size()){
                        break;
                }else{
                        sum += prime[high++];
                }
                if (sum == n) cnt++;
        }
        cout <<cnt;
}