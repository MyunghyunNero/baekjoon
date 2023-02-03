#include <iostream>
using namespace std;
int n,m,r;
int arr[101][101];
int temp[101][101];
void swap(int a,int b,int c,int d){
    int temp= arr[a][b];
    arr[a][b]=arr[c][d];
    arr[c][d]=temp;
}
void one(){
    for(int i=0;i<m;i++){
        for(int j=0;j<n/2;j++){
            swap(j,i,n-j-1,i);
        }
    }
}
void two(){
    for(int i=0;i<n;i++){
        for(int j =0 ;j<m/2;j++){
            swap(i,j,i,m-j-1);
        }
    }
}
void three(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp[j][n-i-1]=arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=temp[i][j];
        }
    }
}
void four(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp[m-j-1][i]=arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=temp[i][j];
        }
    }
}
void five(){
    for(int i=0;i<n/2;i++){
        for(int j=0;j<m/2;j++){
            temp[i][j+m/2]=arr[i][j];
        }
    }
    for(int i=0;i<n/2;i++){
        for(int j=m/2;j<m;j++){
            temp[i+n/2][j]=arr[i][j];
        }
    }
    for(int i=n/2;i<n;i++){
        for(int j=0;j<m/2;j++){
            temp[i-n/2][j]=arr[i][j];
        }
    }
    for(int i=n/2;i<n;i++){
        for(int j=m/2;j<m;j++){
            temp[i][j-m/2]=arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j]=temp[i][j];
        }
    }
}
void six(){
    for(int i=0;i<n/2;i++){
        for(int j=0;j<m/2;j++){
            temp[i+n/2][j]=arr[i][j];
        }
    }
    for(int i=0;i<n/2;i++){
        for(int j=m/2;j<m;j++){
            temp[i][j-m/2]=arr[i][j];
        }
    }
    for(int i=n/2;i<n;i++){
        for(int j=0;j<m/2;j++){
            temp[i][j+m/2]=arr[i][j];
        }
    }
    for(int i=n/2;i<n;i++){
        for(int j=m/2;j<m;j++){
            temp[i-n/2][j]=arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j]=temp[i][j];
        }
    }
}
int main(){
    cin>>n>>m>>r;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<r;i++){
        int a;
        cin>>a;
        if(a==1) one();
        else if(a==2) two();
        else if(a==3) {
        	three();
        	int tem = n;
        	n=m;
        	m=tem;
        }
        else if(a==4) {
        	four();
        	int tem = n;
        	n=m;
        	m=tem;
        }
        else if(a==5) five();
        else if(a==6) six();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
}