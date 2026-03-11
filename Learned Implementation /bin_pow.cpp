//Modular Binary Exponentiation : Time Complexity = O(b) ; b is the exp

int binpow(int a,int b,int mod){
    a%=mod;
    if(b==0){
        return 1;
    }
    if(b&1){
        return a*binpow(a,b-1,mod)%mod;
    }else {
        int temp=binpow(a,b/2,mod)%mod;
        return temp*temp%mod;
    }
}
