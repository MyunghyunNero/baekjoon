#include <iostream>
using namespace std;
long long x,y;
int main(){
    cin>>x>>y;
    int z=(y*100)/x;
    if(z>=99){
        cout<<-1;
        return 0;
    }
    int low=0,high=1000000000;
    int result=-1;
    while(low<=high){
        int mid=(low+high)/2;
        int temp = (100 * (y +mid)) / (x + mid);
        if(z>=temp){
            result=mid+1;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    cout<<result;
}