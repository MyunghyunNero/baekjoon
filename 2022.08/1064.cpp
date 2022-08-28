#include <bits/stdc++.h>
using namespace std;
double a1,b1,a2,b2,a3,b3;
double Dist(double A1, double B1, double A2, double B2){
    return sqrt((A1-A2)*(A1-A2)+(B1-B2)*(B1-B2));
}
int main(){
    cin>>a1>>b1>>a2>>b2>>a3>>b3;
    if(abs(b2-b1)/abs(a2-a1)==abs(b3-b2)/abs(a3-a2)) {
        cout << "-1.0";
        return 0;
    }
    double d1=Dist(a1,b1,a2,b2);
    double d2=Dist(a1,b1,a3,b3);
    double d3=Dist(a2,b2,a3,b3);
    double len1=2*(d1+d2);
    double len2=2*(d2+d3);
    double len3=2*(d3+d1);
    cout<<fixed;
    cout.precision(16);
    cout << max(len1,max(len2,len3)) - min(len1,min(len2,len3)) << '\n';
    return 0;
}