class Solution {
    public:
    int n;
    int solve(int ind,int prev,vector<int>& nums,vector<vector<int>> &dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int len=0+solve(ind+1,prev,nums,dp);
        if(prev==-1||nums[ind]>nums[prev]){
            len=max(len,1+solve(ind+1,ind,nums,dp));
        }
        return dp[ind][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};
