#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;
vector<int> b;
vector<int> ans;
void merge(int alen,int blen){
    int i=0,k=0;
    while(1){
        if(a[i]>=b[k]){
            ans.push_back(b[k]);
            k++;
            if(k==blen){
                break;
            }
        }
        else if(a[i]<b[k]){
            ans.push_back(a[i]);
            i++;
            if(i==alen){
                break;
            }
        }
    }
    if(i==alen){
        for(int t=k;t<blen;t++){
            ans.push_back(b[t]);
        }
    }
    else if(k==blen){
        for(int t=i;t<alen;t++){
            ans.push_back(a[t]);
        }
    }
}
int main(){
    int n,m;
    cin >> n>>m;
    for(int i=0;i<n;i++){
        int z;
        cin >>z;
        a.push_back(z);
    }
    for(int i=0;i<m;i++){
        int z;
        cin >> z;
        b.push_back(z);
    }
    merge(n,m);
    for(int i=0;i<n+m-1;i++){
        cout<< ans[i]<< " ";
    }
    cout << ans[n+m-1];

}