//returns the highest power of prime p in N!
//Time Complexity : O(log N) base is p
int legendre(int n,int p){
    int ans=0;
    for(int i=p;i<=n;i*=p){
        ans+=n/i;
    }return ans;
}

    
