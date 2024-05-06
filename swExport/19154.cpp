#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    int num =1;
    while(num<=t){
        int dp[51][2][2][2];
        vector<vector<int>> agents;
        int n;
        cin>>n;
        for(int i = 0; i < n ;i++){
            vector<int> agent;
            for(int j = 0 ; j < 3 ;j++){
                int stat;
                cin>>stat;
                agent.push_back(stat);
            }
            agents.push_back(agent);
        }
        if(n<3){
            cout<<'#'<<num<<' '<<-1<<'\n';
            num++;
            continue;
        }
        dp[0][1][0][0]=agents[0][1]+agents[0][2];
        dp[0][0][1][0]=agents[0][0]+agents[0][2];
        dp[0][0][0][1]=agents[0][0]+agents[0][1];
        dp[0][1][1][0]=0;
        dp[0][0][1][1]=0;
        dp[0][1][0][1]=0;
        dp[0][1][1][1]=0;
        dp[1][1][1][1]=0;
        for(int i=1;i<n;i++){
            int sumAgentStat = agents[i][0] + agents[i][1] + agents[i][2];
            dp[i][1][0][0] = dp[i-1][1][0][0]+agents[i][1]+agents[i][2];
            dp[i][1][1][0] = min(dp[i-1][1][0][0]+agents[i][0]+agents[i][2], dp[i-1][0][1][0]+agents[i][1]+agents[i][2]);
            if(i>1){
                int maxAgentStat1 = max(agents[i][0],agents[i][1]);
                dp[i][1][1][0] = min(dp[i][1][1][0],dp[i-1][1][1][0]+sumAgentStat-maxAgentStat1);
            }
            dp[i][0][1][0] = dp[i-1][0][1][0]+agents[i][0]+agents[i][2];
            dp[i][0][1][1] = min(dp[i-1][0][1][0]+agents[i][0]+agents[i][1], dp[i-1][0][0][1]+agents[i][0]+agents[i][2]);
            if(i>1){
                int maxAgentStat2 = max(agents[i][1],agents[i][2]);
                dp[i][0][1][1] = min(dp[i][0][1][1],dp[i-1][0][1][1]+sumAgentStat-maxAgentStat2);
            }
            dp[i][0][0][1] = dp[i-1][0][0][1]+agents[i][0]+agents[i][1];
            dp[i][1][0][1] = min(dp[i-1][1][0][0]+agents[i][0]+agents[i][1], dp[i-1][0][0][1]+agents[i][1]+agents[i][2]);
            if(i>1){
                int maxAgentStat3 = max(agents[i][0],agents[i][2]);
                dp[i][1][0][1] = min(dp[i][1][0][1],dp[i-1][1][0][1]+sumAgentStat-maxAgentStat3);
            }
            if(i>1){
                dp[i][1][1][1] = min(min(dp[i-1][1][1][0]+agents[i][0]+agents[i][1],dp[i-1][0][1][1]+agents[i][1]+agents[i][2])
                            ,dp[i-1][1][0][1]+agents[i][0]+agents[i][2]);
            }
            if(i>2){
                int maxAgentStat = max(max(agents[i][0],agents[i][1]),agents[i][2]);
                dp[i][1][1][1] = min(dp[i][1][1][1],dp[i-1][1][1][1] + sumAgentStat - maxAgentStat);
            }
            
        }
        cout<<'#'<<num<<' '<<dp[n-1][1][1][1]<<'\n';
        num++;
    }
}