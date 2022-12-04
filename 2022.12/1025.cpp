#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
int ans = -1;
int arr[10][10];
bool isSqureNumber(int n) {
    int root = (int)sqrt(n);
    if (root * root == n) return true;
    else return false;
}
int main() {
    cin >> n >> m;
    string str = "";
    for (int i = 1; i <= n; i++) {
        cin >> str;
        for (int j = 1; j <= m; j++) {
            arr[i][j] = (int)str[j-1]-'0';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int x = -n; x < n ; x++) {//행의 등차 값
                for (int y = -m; y < m; y++) {//열의 등차 값
                    if (x == 0 && y == 0) continue;
                    int a = i, b = j;
                    int now = 0;
                    while (a > 0 && a <= n && b > 0 && b <= m) {
                        now *= 10;
                        now += arr[a][b];
                        if (isSqureNumber(now)) ans = max(ans, now);
                        a += x;
                        b += y;
                    }
                    if (isSqureNumber(now)) ans = max(ans, now);
                }
            }
        }
    }
    cout << ans << '\n';
}
