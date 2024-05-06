#include <iostream>
#include <vector>
using namespace std;
vector<int> rowCnt;
int rowSize;
void init(){
    int startNum = 1;
    int incNum = 1;
    rowCnt.push_back(0);
    for(int i=startNum ; i<=10011;i+=incNum){  //10000 범위 안에서 올바르게 삼각형 쌓이는 값이 최대 10011
        rowCnt.push_back(i);
        incNum++;
    }
    rowSize = rowCnt.size();
}
pair<int,int> binarySearch(int target)
{
	int low = 0;
	int high = rowSize - 1;
	int mid = 0;
    pair<int,int> rowAndCol;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (target < rowCnt[mid]){
			high = mid - 1;
        }else if (target > rowCnt[mid]){
			low = mid + 1;
        }else{
            rowAndCol = {mid,target-rowCnt[mid-1]};
			return rowAndCol;
        }
	}
    rowAndCol = {low,target-rowCnt[low-1]};
	return rowAndCol;
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int t;
    int num=1;
    cin>>t;
    while(num<=t){
        int s,e;
        cin>>s>>e;
        pair<int,int> startPosition = binarySearch(s);
        pair<int,int> endPosition = binarySearch(e);
        int startRow = startPosition.first;
        int startCol = startPosition.second;
        int endRow = endPosition.first;
        int endCol = endPosition.second;
        int answer = 0;
        if(startRow < endRow) {
            int rowDiff = endRow - startRow;
            if(startCol <= endCol && startCol+rowDiff >= endCol) {
                answer = rowDiff;
            }else{
                answer = rowDiff + min(abs(endCol-startCol),abs(endCol - (startCol+rowDiff)));
            }
        }else if(startRow > endRow) {
            int rowDiff = startRow - endRow;
            if(startCol-rowDiff <= endCol && startCol>= endCol){
                answer = rowDiff;
            }else{
                answer = rowDiff + min(abs(endCol-startCol),abs(endCol - (startCol-rowDiff)));
            }
        }else{
            answer = abs(endCol - startCol);
        }
        cout<<"#"<<num<<' '<<answer<<'\n';
        num++;
    }
}