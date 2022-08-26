#include <iostream>
#include <string>
using namespace std;
int main(void)
{

    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = s;
    for (int i = 1; i < n;i++)
    {
    string temp;
    cin>> temp;
        for (int j = 0; j <s.length(); j++){
            if (s[j] != temp[j])
                ans[j] = '?';
        }
    }
    cout << ans << "\n";
    return 0;
}
