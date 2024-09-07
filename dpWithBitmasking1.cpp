
#include <bits/stdc++.h>
using namespace std;

int cost[21][21];
int dp[21][(1<<21)];
int solve(int i,int mask,int &n)
{
    if(i==n) return 0;
    if(dp[i][mask]!=-1) return dp[i][mask];
    int answer=INT_MAX;
    for(int j=0;j<n;j++){
        if(mask&(1<<j)){
            answer=min(answer,cost[j][i]+solve(i+1,(mask^(1<<j)),n));
        }
    }
    return dp[i][mask]=answer;
}
int main()
{
    int t=1;
    memset(dp,-1,sizeof dp);
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>cost[i][j];
            }
        }
        cout<<solve(0,(1<<n)-1,n)<<endl;
    }
    return 0;
}
