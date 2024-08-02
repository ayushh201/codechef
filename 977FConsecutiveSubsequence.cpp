#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int n,a[N];

map<int,int> dp;
int res=INT_MIN,curr;
vector<int> v;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        dp[a[i]]=max(dp[a[i]],dp[a[i]-1]+1);
        if(dp[a[i]]>res){
            res=dp[a[i]];
            curr=a[i];
        }
    }
    cout<<res<<endl;
    for(int i=n-1;i>=0;i--){
        if(a[i]==curr){
            curr--;
            v.push_back(i);
        }
    }
    reverse(v.begin(),v.end());
    for(int &it:v){
        cout<<it+1<<" ";
    }
}
