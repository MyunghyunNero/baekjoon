#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
bool check[1000001];
int n;
int ans;
int main(){
    cin>>n;
    int maxh=0;
    int minh=987654321;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<n;i++){
        if(check[i]) continue;
        int h=v[i];
        ans++;
        h--;
        for(int j=i+1;j<n;j++){
            if(h==v[j] && !check[j]){
                h--;
                check[j]=true;
            }
        }
    }
    cout<<ans;

}