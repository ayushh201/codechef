class Solution {
public:
    int M=1e9+7;
    typedef long long ll;
    int maximumXorProduct(long long a, long long b, int n) {
        ll xa=0, xb=0;
        for(ll i=49;i>=n;i--){
            bool a_ith_bit=((a>>i)&1)>0;
            bool b_ith_bit=((b>>i)&1)>0;
            if(a_ith_bit==true){
                xa=(xa^(1ll<<i));
            }
            if(b_ith_bit==true){
                xb=(xb^(1ll<<i));
            }
        }
        for(ll i=n-1;i>=0;i--){
            bool a_ith_bit=((a>>i)&1)>0;
            bool b_ith_bit=((b>>i)&1)>0;
            if(a_ith_bit==b_ith_bit){
                xa=(xa^(1ll<<i));
                xb=(xb^(1ll<<i));
                continue;
            }
            if(xa>xb){
                xb=(xb^(1ll<<i));
            }else{
                xa=(xa^(1ll<<i));
            }
        }
        xa=(xa%M);
        xb=(xb%M);
        return (xa*xb)%M;
    }
};
