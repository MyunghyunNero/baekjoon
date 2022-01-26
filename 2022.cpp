#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    double x,y,c;
    scanf("%lf %lf %lf",&x,&y,&c);
    double left=0;
    double right=min(x,y);
    while (abs(right-left)>1e-6)
    {
        double mid=(left+right)/2.0;
        double d=mid;                       //건물 사이 거리
        double h1=sqrt(x*x-d*d);           //x사다리의 높이
        double h2=sqrt(y*y-d*d);          //y사다리 높이
        double h=(h1*h2)/(h1+h2);          //구해야하는 높이
        if(h>c){
            left=mid;
        }
        else{
            right=mid;
        }
    }
    printf("%.3lf",left);
    return 0;
    
}