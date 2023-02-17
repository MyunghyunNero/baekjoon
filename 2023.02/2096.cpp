#include <iostream>
#include <algorithm>
using namespace std;
int maxDp[3];
int minDp[3];
int input[3];
int main(){
    int n,temp_0, temp_2;;
    cin>>n;
    cin>>maxDp[0]>>maxDp[1]>>maxDp[2];
    minDp[0] = maxDp[0]; minDp[1] = maxDp[1]; minDp[2] = maxDp[2];
    for(int i=1;i<n;i++){
        cin>>input[0]>>input[1]>>input[2];
        temp_0 = maxDp[0]; temp_2 = maxDp[2];
        maxDp[0] = max(maxDp[0], maxDp[1]) + input[0];
        maxDp[2] = max(maxDp[1], maxDp[2]) + input[2];
        maxDp[1] = max(max(temp_0, maxDp[1]), temp_2) + input[1];
        //최소값을 구해주는 DP배열
        temp_0 = minDp[0]; temp_2 = minDp[2];
        minDp[0] = min(minDp[0], minDp[1]) + input[0];
        minDp[2] = min(minDp[1], minDp[2]) + input[2];
        minDp[1] = min(min(temp_0, minDp[1]), temp_2) + input[1];
    }
    cout<<max(max(maxDp[0], maxDp[1]), maxDp[2])<<' '<<min(min(minDp[0], minDp[1]), minDp[2]);

}