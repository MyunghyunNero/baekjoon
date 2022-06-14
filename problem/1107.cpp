#include <iostream>
using namespace std;
bool broke[10];
int remote(int a){
	    if(a==0){
			if(broke[0]){
               return 0;
	        }
            else{
	           return 1;
	        }
        }
	    int len=0;
	    while(a>0){
	        if(broke[a%10])
	            return 0;
            len++;
		            a=a/10;
	    }
	    return len;
}
int main(){
    int chanel;
    int n;
    int a;
    cin >>chanel;
    cin >>n;
    while(n--){
	    cin>>a;
	    broke[a]=true;
    }
    int ans=chanel-100;
    if(ans<0)
        ans=-ans;
    for(int i=0;i<1000000;i++){
	    int c=i;
	    int len=remote(c);
	    if(len>0){
		    int cnt=c-chanel;
        if(cnt<0)
	       cnt=-cnt;
        if(ans>len+cnt)
           ans=len+cnt;
       }
    }
    cout<<ans;
}

