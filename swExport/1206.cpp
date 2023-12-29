#include <iostream>
using namespace std;
int main(){
    int t = 1;
    while(t<=10){
        int n;
        int height[1001];
        int ans=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>height[i];
        }
        for(int i=2;i<n-2;i++){
            int maxValue=0;
            for(int j=i-2;j<=i+2;j++){
                if(j==i) continue;
                maxValue = max(maxValue,height[j]);
            }
            if(height[i]>maxValue){
                ans+=height[i]-maxValue;
            }
        }
        cout<<'#'<<t<<' '<<ans<<'\n';
        t++;
    }
}