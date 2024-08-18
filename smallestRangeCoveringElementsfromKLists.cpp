class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> arr;
        for(int i=0;i<nums.size();i++){
            for(auto &j:nums[i]) arr.push_back({j,i});
        }
        sort(arr.begin(),arr.end());
        map<int,int> mp;
        vector<int> ans{1,(int)1e9};
        
        for(int i=0,j=0;i<arr.size();i++){
            mp[arr[i].second]++;
            if(mp.size()==nums.size()){
                while(mp.size()==nums.size()){
                    mp[arr[j].second]--;
                    if(mp[arr[j].second]==0) mp.erase(arr[j].second);
                    j++;
                }
                j--;
                mp[arr[j].second]++;
                if(arr[i].first-arr[j].first<ans[1]-ans[0]){
                    ans={arr[j].first,arr[i].first};
                }
            }
        }
        return ans;
    }
};
