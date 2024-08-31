class Solution {
public:
    int noOfOnes(int num){
        int count=0;
        while(num!=0){
            count+=(num&1); //compute the lsb
            num>>=1; //right shift
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda = [&](int &a,int &b){
            int count_a=noOfOnes(a);
            int count_b=noOfOnes(b);
            if(count_a==count_b) return a<b;
            return count_a<count_b;
        };
        sort(arr.begin(),arr.end(),lambda);
        return arr;
    }
};
