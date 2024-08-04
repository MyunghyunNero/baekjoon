using namespace std;
int gcd(int a,int b) {
    while(b) {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
long long solution(int w,int h) {
    long long answer = 1;
    long long sum = (long long)w*(long long)h;
    sum -=((long long)w+(long long)h-gcd(w,h));
    
    return sum;
}