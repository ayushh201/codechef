class Solution {
public:
    int cal(int i,int j,vector<int>& nums,vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maximum=INT_MIN;
        for(int ind=i;ind<=j;ind++){
            int cost=(nums[i-1]*nums[ind]*nums[j+1])+cal(i,ind-1,nums,dp)+cal(ind+1,j,nums,dp);
            maximum=max(maximum,cost);
        }
        return dp[i][j]=maximum;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        return cal(1,n,nums,dp);
    }
};
