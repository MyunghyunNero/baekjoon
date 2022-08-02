#include <iostream>
#include <algorithm>
using namespace std;
int v,e;
int arr[101][101];
int from, to, weight;
void floyd() {
    for (int i = 1; i <= v; i++)         
        for (int j = 1; j <= v; j++)        
            for (int k = 1; k <= v; k++)   
                if (arr[j][i] != 987654321 && arr[i][k] != 987654321)        
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
}
int main(){
    cin >> v >> e;
    for (int i = 1; i <= v; i++) {       
        for (int j = 1; j <= v; j++) {
            arr[i][j] = 987654321;
                arr[i][j]==0;
        }
    }
    for (int i = 0; i < e; i++) {  
        cin >> from >> to >> weight;
        if (arr[from][to] > weight) 
            arr[from][to] = weight;
    }
    floyd();
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (i==j ||arr[i][j] == 987654321)
                cout << 0 << " ";
            else
                cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
