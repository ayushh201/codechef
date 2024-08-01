class Solution {
    private:
    int solve(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int nonpick=0+prev;
            int curr=max(pick,nonpick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(nums[i]);
        if(i!=n-1)temp2.push_back(nums[i]);
        }
        return max(solve(temp1),solve(temp2));
    }
};
