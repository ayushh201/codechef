#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    long long int n,a[100001],b[100001],dp[100001];
    cin>>n;
    for(long long int i=0;i<n;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    dp[1]=b[1];
    for(long long int i=2;i<100001;i++){
        dp[i]=max(dp[i-1],(i*b[i])+dp[i-2]);
    }
    cout<<dp[100000];
}
