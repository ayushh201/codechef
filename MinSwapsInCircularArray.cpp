//A swap is defined as taking two distinct positions in an array and swapping the values in them.A circular array is defined as an array where we consider the first element and the last element to be adjacent.Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int noOfOnes=accumulate(nums.begin(),nums.end(),0);
        int i=0,j=0;
        int currentOnes=0;
        int maxOnes=0;
        while(j<2*n){
            if(nums[j%n]==1){
                currentOnes++;
            }
            if(j-i+1>noOfOnes){
                currentOnes-=nums[i%n];
                i++;
            }
            maxOnes=max(maxOnes,currentOnes);
            j++;
        }
        return noOfOnes-maxOnes;
    }
};
