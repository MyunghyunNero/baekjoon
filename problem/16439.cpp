#include <iostream>
using namespace std;
int a[32][32];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
            cin>>a[i][k];
        }
    }
    int ans=0;
    int max=0;
    for(int i=0;i<m;i++){
        for(int k=i;k<m;k++){
            for(int j=k;j<m;j++){
                for(int t=0;t<n;t++){
                    if(a[t][i]>=a[t][k]&&a[t][i]>=a[t][j])
                        ans+=a[t][i];
                    else if(a[t][k]>=a[t][i]&&a[t][k]>=a[t][j])
                        ans+=a[t][k];
                    else if(a[t][j]>=a[t][i]&&a[t][j]>=a[t][k])
                        ans+=a[t][j];
                }
                if(max<ans)
                    max=ans;
                ans=0;
            }
        }
    }
    cout<< max;
    return 0;
}