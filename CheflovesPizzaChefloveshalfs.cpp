#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int x;
	    cin>>x;
	    if(__builtin_popcount(x)==1){ //power of 2 check
	        cout<<0<<endl;
	    }
	    else{
	        int i=31-(__builtin_clz(x));
	        int nearest=(1<<i);
	        cout<<(x-nearest)*2<<endl;
	    }
	}
}
