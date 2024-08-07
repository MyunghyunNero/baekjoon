#include <iostream>
#include<vector>
using namespace std;
int solution(vector<vector<int>> board)
{
    int answer = board[0][0];

    int colSize = board.size();
    int rowSize = board[0].size();
    for(int i=1;i<colSize;i++) {
        for(int j=1;j<rowSize;j++) {
            if(board[i][j]==1) {
                board[i][j] = min(board[i-1][j], board[i][j-1]);
                board[i][j] = min(board[i-1][j-1],board[i][j])+1;
                answer=max(board[i][j],answer);
            }
        }
        
    }

    return answer*answer;
}