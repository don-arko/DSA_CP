//Time Complexity : O(MAX)
//Precomputes all the (factorials and their inverse)%MOD 
//Constraint : r,n  <=1e6 ; r<=n
const int MAX=1e6;
void factorials(){              //O(MAX)
    fact[0] = 1;
    for(int i = 1; i <= MAX; i++){
        fact[i] = i * fact[i-1]  % MOD;
    }

    inv_fact[MAX] = binpow(fact[MAX], MOD-2, MOD);

    for(int i = MAX-1; i >= 0; i--){
        inv_fact[i] =(i+1) * inv_fact[i+1] % MOD;
    }
}
