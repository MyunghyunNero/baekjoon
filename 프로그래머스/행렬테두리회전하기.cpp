#include <string>
#include <vector>

using namespace std;

int arr[101][101];
int spin(vector<int> query){
    int x1=query[0]-1;
    int y1=query[1]-1;
    int x2=query[2]-1;
    int y2=query[3]-1;
    int mans=arr[x1][y1];
    int pre = arr[x1][y1];
    for(int i=y1+1;i<=y2;i++){
        mans=min(mans,arr[x1][i]);
        int temp=arr[x1][i];
        arr[x1][i]=pre;
        pre=temp;
    }
    for(int i=x1+1;i<=x2;i++){
        mans=min(mans,arr[i][y2]);
        int temp=arr[i][y2];
        arr[i][y2]=pre;
        pre=temp;
    }
    for(int i=y2-1;i>=y1;i--){
        mans=min(mans,arr[x2][i]);
        int temp=arr[x2][i];
        arr[x2][i]=pre;
        pre=temp;
    }
    for(int i=x2-1;i>=x1;i--){
        mans=min(mans,arr[i][y1]);
        int temp=arr[i][y1];
        arr[i][y1]=pre;
        pre=temp;
    }
    return mans;
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int cnt=1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            arr[i][j]=cnt++;
        }
    }
    for(int i=0;i<queries.size();i++){
        answer.push_back(spin(queries[i]));
    }
    return answer;
}