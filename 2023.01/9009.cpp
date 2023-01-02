#include <iostream>
#include <vector>
using namespace std;
long long fib[10001];

int n;
int maxIndex;
int binarysearch(int target){
    int low = 0;
    int high=maxIndex;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(fib[mid]==target){
            return mid;
        }else if(fib[mid]>target){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;
    
}
int main(){
    fib[0]=0;
    fib[1]=1;
    int t;
    cin>>t;
    for(int i=2;fib[i-1]<=1000000000;i++){
        fib[i]=fib[i-1]+fib[i-2];
        maxIndex=i;
    }
    while(t--){
        cin>>n;
        vector<int> v;
        int index = binarysearch(n);
        for(int i = index ; i>=0;i--){
        	if(n==0){
        		break;
        	}
            if(fib[i]<=n){
                v.push_back(fib[i]);
                n-=fib[i];
            }
        }
        for(int i= v.size()-1;i>=0;i--){
            cout<< v[i]<<" ";
        }
        cout<<'\n';
    }
}