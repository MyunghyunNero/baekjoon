#include <iostream>
#include <vector>
using namespace std;
vector<long long> city;
vector<long long> len;
long long n, sum;
int check;
void add(int a, int n) {
    
    long long lensum = 0;
    for (int i = a + 1; i < n; i++) {
        if (city[a] > city[i]) {          //값이 작은 게 나오면 거기까지 가격 구하기
            lensum += len[i - 1];
            sum += (lensum * city[a]);
            add(i, n);                    //그리고 재귀
            return;
        }
        lensum += len[i - 1];
    }
    sum+= (lensum * city[a]);                  //작은게 없을경우 
    return;

}
int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        long long temp;
        cin >> temp;
        len.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        city.push_back(temp);
    }
    add(0, n);
    cout << sum;
}