class Solution {
    private:
    int solve(int ind,int tr,vector<int> &prices,vector<vector<int>> &dp){
        if(ind==prices.size()||tr==4) return 0;
        if(dp[ind][tr]!=-1) return dp[ind][tr];
        int profit=0;
        if(tr%2==0){
            profit=max(-prices[ind]+solve(ind+1,tr+1,prices,dp),0+solve(ind+1,tr,prices,dp));
        }else{
            profit=max(prices[ind]+solve(ind+1,tr+1,prices,dp),0+solve(ind+1,tr,prices,dp));
        }
        return dp[ind][tr]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return solve(0,0,prices,dp);
    }
};
