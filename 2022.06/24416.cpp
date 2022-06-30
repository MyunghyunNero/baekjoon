    #include <iostream>
    using namespace std;
    int f[41];
    int cnt1=1;
    int cnt2=0;
    int fib(int n) {
        
        if (n == 1 || n == 2)
        return 1; 
        else {
            cnt1++;
            return (fib(n - 1) + fib(n - 2));
        }
    }
    int fibonacci(int n) {
        f[1] =1;
        f[2]=1;
        for(int i=3;i<=n;i++){
            cnt2++;
            f[i]= f[i - 1] + f[i - 2];
        }

        return cnt2;
    }
    int main(){
        int n;
        cin>>n;
        fib(n);
        fibonacci(n);
        cout<<cnt1<<' '<<cnt2;

    }