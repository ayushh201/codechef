#include<bits/stdc++.h>
using namespace std;

int calculateLis(vector<int> &arr){
    int n=arr.size();
    int maximum=1, lastIndex=0;
    vector<int> dp(n,1), hash(n);
    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int prev=0;prev<i;prev++){
            if(arr[prev]<arr[i] && 1+dp[prev]>dp[i]){
                dp[i]=1+dp[prev];
                hash[i]=prev;
            }
        }
        if(dp[i]>maximum){
            maximum=dp[i];
            lastIndex=i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while(hash[lastIndex]!=lastIndex){
        lastIndex=hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(),temp.end());
    for(int i=0;i<temp.size();i++) cout<<temp[i]<<" ";
    cout<<endl;
    return maximum;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=calculateLis(arr);
    cout<<ans<<endl;
}
