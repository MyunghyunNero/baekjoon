    #include <iostream>
    #include <queue>
    #include <algorithm>
    using namespace std;
    int v,e;
    int arr[401][401];
    int from, to, weight;
    int ans=987654321;
    void floyd() {
        for (int i = 1; i <= v; i++)         
            for (int j = 1; j <= v; j++)        
                for (int k = 1; k <= v; k++)          
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
    }
    int main(){
        cin>>v>>e;
        for (int i = 1; i <= v; i++) {       
            for (int j = 1; j <= v; j++) {
                arr[i][j] = 987654321;
            }
        }
        for (int i = 0; i < e; i++) {  
            cin >> from >> to >> weight;
            arr[from][to] = weight;
        }
        floyd();
        for(int i=1;i<=v;i++){
            for(int k=1;k<=v;k++){
                if(i!=k){
                    ans=min(ans,arr[i][k]+arr[k][i]);
                }   
            }
        }
        if(ans==987654321){
            cout << -1;
        }else{
            cout <<ans;
        }
    }