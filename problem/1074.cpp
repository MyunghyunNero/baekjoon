#include <iostream>

using namespace std;

int n, r, c;
int ans;

void search(int x, int y, int size)     //내가 찾는 행과 열 탐색하는 함수
{
    if (y == r && x == c)
    {
        cout << ans << '\n';
        return;
    }
    if (r < y + size && r >= y && c < x + size && c >= x) //현재 size에 해당하는 크기에 내가 원하는 행과열 있다면
    {
        search(y, x, size / 2);                        //1사분면 탐색
        search(y, x + size / 2, size / 2);             //2사분면 탐색
        search(y + size / 2, x, size / 2);             //3사분면 탐색
        search(y + size / 2, x + size / 2, size / 2);  //4사분면 탐색
    }
    else                          //없으면 크기 값 더하기
    {
        ans += size * size;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> c;
    search(0, 0, (1 << n));
    return 0;
}