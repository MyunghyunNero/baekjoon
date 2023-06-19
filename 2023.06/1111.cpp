#include <iostream>
#include <vector>
using namespace std;
vector<int> v; 
int main(){
    int n,x,y;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    if (n == 1){
		cout << "A\n";
		return 0;
	}
	if (n == 2){
		if (v[0] == v[1])
			cout << v[1];
		else
			cout << "A\n";
		
		return 0;
	}
    x=0;
    if(v[1]-v[0]!=0){
        x=(v[2]-v[1])/(v[1]-v[0]);
    }
    
    y=v[1]-v[0]*x;
    for(int i=2;i<n;i++){
        if((v[i-1]*x+y)!=v[i]){
            cout<<"B";
            return 0;
        }
    }
    cout<<v[n-1]*x+y;
}