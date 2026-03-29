//Modular Binary Exponentiation : Time Complexity = O(b) ; b is the exp
//computes a^b mod m
int binpow(int a,int b,int m){
    a%=m;
    if(b==0) return 1;
    if(b&1) return a*binpow(a,b-1,m)%m;
    else {
        int temp=binpow(a,b/2,m)%m;
        return (temp*temp)%m;
    }
}
