// Problem statement : Find primes in the range [l,....r] ;  0< l<=r <1e12 & r-l+1<=1e6 ; 
vector<int> sieve(int n){
    vector<int> prime;
    vector<bool> is_prime(n+1,true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            prime.push_back(i);
            for(int j=i*i;j<=n;j+=i){
                is_prime[j]=false;
            }
        }
    }
    return prime;
}
vector<int> segmentedsieve(int l,int r){
    //Phase 1:
    vector<int> base_prime=sieve(ceil(sqrt(r)));
    //Phase 2:
    vector<bool> is_prime(r-l+1,true);
    if(l==1) is_prime[0]=false; // lmin=1 and 1 is the  only non prime that couldn't be stiked off by a smaller prime
    for(auto p:base_prime){
        int curMul=((l+p-1)/p)*p;  //first multiple of p in [l,r]
        curMul=max(curMul,p*p);  // k min= pmin = 2>1 hence first multiple of p i.e. p itself if never considered
        //marking multiples of p in [l,r] except p itself as non prime
        while(curMul<=r){
            is_prime[curMul-l]=false;
            curMul+=p;
        }
    }
    //collecting all the primes in the range [l,r]
    vector<int> prime; 
    for(int i=0;i<r-l+1;++i){
        if(is_prime[i]){
            prime.push_back(i+l);
        }
    }
    return prime;
}
