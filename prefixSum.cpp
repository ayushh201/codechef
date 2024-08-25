//303. Range Sum Query - Immutable
class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        prefix.resize(n+1);
        prefix[0]=0;
        for(int i=0;i<n;i++){
            prefix[i+1]=nums[i]+prefix[i];
        }
    }
    
    int sumRange(int left, int right) {
        return (prefix[right+1]-prefix[left]);
    }
};

//525. Contiguous Array
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int currentSum=0;
        mp[0]=-1;
        int result=0;
        for(int i=0;i<n;i++){
            currentSum+=(nums[i]==1)? 1:-1;
            if(mp.find(currentSum)!=mp.end()){
                result=max(result,i-mp[currentSum]);
            }else{
                mp.insert({currentSum,i});
            }
        }
        return result;
    }
};

//560. Subarray Sum Equals K
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        mp[0]=1;
        int presum=0, cnt=0;
        for(int i=0;i<n;i++){
            presum+=nums[i];
            int remove=presum-k;
            cnt+=mp[remove];
            mp[presum]++;
        }
        return cnt;
    }
};
