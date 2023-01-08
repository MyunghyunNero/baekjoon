#include <iostream>
#include <string>
#include <vector>
using namespace std;
char arr[101][101];
int main(){
    int n;
    cin >> n;
    int row=0;
    int col=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == '.')
				count++;
			else
			{
				if (count > 1)
					row++;
				count = 0;
			}
		}
		if (count > 1)
			row++;
	}
    for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[j][i] == '.')
				count++;
			else
			{
				if (count > 1)
					col++;
				count = 0;
			}
		}
		if (count > 1)
			col++;
	}


    cout<<row<<' '<<col;
}