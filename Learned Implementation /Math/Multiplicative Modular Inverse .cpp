int binpow(int a,int b,int m){
    a%=m;
    if(b==0) return 1;
    if(b&1) return a*binpow(a,b-1,m)%m;
    else{
        int temp=binpow(a,b/2,m)%m;
        return temp*temp%m;
}

//From Fermat's Little Theorem , if p is prime and a is not congruent to 0 in mod domain of p i.e. a not divisible by b then 
//a^(p-1) is congruent to 1(mod p) => inv(a) =a^(p-2)
int inverse(int a,int m){
    return binpow(a,m-2,m);   // calculates (a inv mod m)
}
