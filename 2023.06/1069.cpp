#include <iostream>
#include <cmath>
using namespace std;
double x,y,d,t;
int main(){
	cin>>x>>y>>d>>t;
    double dis = sqrt(pow(x, 2) + pow(y, 2));
    cout << fixed;
    cout.precision(9);
    if(d<t){
        cout<<dis;
    }else{
        double ans=dis;
        int jump =dis/d;
        dis-=jump*d;

        if(jump==0){
            ans=min(ans,min(t+d-dis,2.0*t));
        }else{
            ans=min(ans,min(jump*t+dis,(jump+1.0)*t));
        }
        cout<<ans;
    }
}