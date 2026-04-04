//Since this method uses fact . It calculates entire Nu first then divide by Deno hence ans can overflow
int fact(int n){       //O(N)
    if(n==0) return 1;
    return n*fact(n-1);
}
int nCr(int n,int r){
    if(r<0 || r>n) return 0;
    int ans=fact(n);
    ans=ans/fact(n-r);
    ans=ans/fact(r);
    return ans;
}
