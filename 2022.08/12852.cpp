#include <iostream>
using namespace std;
pair<int,int> a[1000001];
int n;
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    cin>>n;
    a[1]={0,-1};
    for(int i=2;i<=n;i++){
        a[i]={a[i-1].first+1,i-1};
        if(i%2==0&&a[i].first>a[i/2].first+1){
            a[i]={a[i/2].first+1,i/2};
        }
        if(i%3==0&&a[i].first>a[i/3].first+1){
            a[i]={a[i/3].first+1,i/3};
        }
    }
    cout <<a[n].first<<'\n';
    while(n!=-1){
        cout <<n<<' ';
        n=a[n].second;
    }
}   