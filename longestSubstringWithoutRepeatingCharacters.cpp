class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int> mp;
        int l=0,r=0,maxlength=0;
        while(r<n){
            if(mp.find(s[r])!=mp.end()){
                if(mp[s[r]]>=l){
                    l=mp[s[r]]+1;
                }
            }
            maxlength=max(maxlength,r-l+1);
            mp[s[r]]=r;
            r++;
        }
        return maxlength;
    }
};
