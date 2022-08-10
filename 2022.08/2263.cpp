#include <iostream>

using namespace std;

int Index[100001];
int inorder[100001];
int postorder[100001]; //후위 순위의 마지막은 항상 루트이다 . 즉 루트 인 값을 중위순위에서 찾은후 출력하면 전위순회
int n;
// preorder 를 출력하는 함수 (재귀)         
void getPreOrder(int inStart, int inEnd, int postStart, int postEnd)
{
    if (inStart > inEnd || postStart > postEnd)
        return;
    int rootIndex = Index[postorder[postEnd]];
    int leftSize = rootIndex - inStart;
    cout << inorder[rootIndex] << ' '; // root 값 출력

    // 재귀 함수 호출
    getPreOrder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    getPreOrder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> inorder[i];
        Index[inorder[i]] = i; // inorder 요소들의 Index 정보 저장
    }
    for (int i = 1; i <= n; i++)
        cin >> postorder[i];
    getPreOrder(1, n, 1, n);
    return 0;
}