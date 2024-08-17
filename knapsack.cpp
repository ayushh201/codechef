#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int func(int ind,int W, vector<int>& wt, vector<int>& val)
  {
      if(ind==0){
          if(wt[0]<=W) return val[0];
          return 0;
      }
      int nottake=0+func(ind-1,W,wt,val);
      int take=-1e9;
      if(wt[ind]<=W){
          take=val[ind]+func(ind-1,W-wt[ind],wt,val);
      }
      return max(take,nottake);
  }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n=wt.size();
        return func(n-1,W,wt,val);
    }
};

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}



//memoization

class Solution {
  public:
  int func(int ind,int W, vector<int>& wt, vector<int>& val,vector<vector<int>> &dp)
  {
      if(ind==0){
          if(wt[0]<=W) return val[0];
          return 0;
      }
      if(dp[ind][W]!=-1) return dp[ind][W];
      int nottake=0+func(ind-1,W,wt,val,dp);
      int take=-1e9;
      if(wt[ind]<=W){
          take=val[ind]+func(ind-1,W-wt[ind],wt,val,dp);
      }
      return dp[ind][W]=max(take,nottake);
  }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n=wt.size();
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return func(n-1,W,wt,val,dp);
    }
};

//tabulation

class Solution {
  public:
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n=wt.size();
        vector<vector<int>> dp(n,vector<int>(W+1,0));
        for(int i=wt[0];i<=W;i++) dp[0][i]=val[0];
        for(int ind=1;ind<n;ind++){
            for(int w=0;w<=W;w++){
                int nottake=0+dp[ind-1][w];
                int take=-1e9;
                if(wt[ind]<=w){
                    take=val[ind]+dp[ind-1][w-wt[ind]];
                }
                dp[ind][w]=max(take,nottake);
            }
        }
        return dp[n-1][W];
    }
};

//space optimization

class Solution {
  public:
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n=wt.size();
        vector<int> prev(W+1,0), curr(W+1,0);
        
        for(int i=wt[0];i<=W;i++) prev[i]=val[0];
        for(int ind=1;ind<n;ind++){
            for(int w=0;w<=W;w++){
                int nottake=0+prev[w];
                int take=-1e9;
                if(wt[ind]<=w){
                    take=val[ind]+prev[w-wt[ind]];
                }
                curr[w]=max(take,nottake);
            }
            prev=curr;
        }
        return prev[W];
    }
};

//further

class Solution {
  public:
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n=wt.size();
        vector<int> prev(W+1,0);
        
        for(int i=wt[0];i<=W;i++) prev[i]=val[0];
        for(int ind=1;ind<n;ind++){
            for(int w=W;w>=0;w--){
                int nottake=0+prev[w];
                int take=-1e9;
                if(wt[ind]<=w){
                    take=val[ind]+prev[w-wt[ind]];
                }
                prev[w]=max(take,nottake);
            }
        }
        return prev[W];
    }
};

