class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> low,high;
        vector<double> median;
        
        for(int i=0;i<nums.size();i++){
            low.insert(nums[i]);
            high.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
            
            if(low.size()<high.size()){
                low.insert(*high.begin());
                high.erase(high.find(*high.begin()));
            }
            
            if(i>=k-1){
                if(k&1) median.push_back(*low.rbegin());
                else median.push_back(((double)*low.rbegin()+(double)*high.begin())/2.0);
                
                if(nums[i-k+1]<=*low.rbegin()) low.erase(low.find(nums[i-k+1]));
                else high.erase(high.find(nums[i-k+1]));
            }
        }
        return median;
    }
};
