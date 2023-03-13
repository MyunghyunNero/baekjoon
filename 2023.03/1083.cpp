#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int n,s;
void swap(int a){
    int temp=v[a];
    v[a]=v[a+1];
    v[a+1]=temp;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    cin>>s;
    for (int i = 0; i < n; i++)
	{
		int max = v[i];
		int maxi = i;
		for (int j = i + 1; j < n; j++)
		{
			if (s - (j - i) >= 0)
			{
				if (max < v[j])
				{
					max = v[j];
					maxi = j;
				}
			}
		}
		for (int j = maxi; j > i; j--)
			swap(v[j], v[j - 1]);
		s -= (maxi - i);
		if (s <= 0)
			break;
	}
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}