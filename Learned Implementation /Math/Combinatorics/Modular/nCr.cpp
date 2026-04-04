//Time Complexity : O(rlog(MOD))
// Calculates nCr % MOD 
//constraint : n<=10^6 and ofc r<=10^6 (r<=n)

#define int long long int
const int MOD = 1e9+7;
int nCr(int n,int r){             //O(r.log(MOD))
    if(r>n || r<0 ) return 0;    //nCr=0 ; r>n
    r=min(r,n-r);       // optimisation as nCr=nCn-r
    int res=1;
    for(int i=0;i<r;i++){
        res=(res*(n-i))%MOD;
        res=res*(binpow(i+1,MOD-2,MOD))%MOD; //= (res*(binpow(i+1,MOD-2,MOD)))%MOD  as associativity is Left to right
    }
    return res;
}
