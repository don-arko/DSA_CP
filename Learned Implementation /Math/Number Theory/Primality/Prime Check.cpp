// Time Complexity : O(sqrt(N))

bool isPrime(int n){
    if(n>=2){
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }return true;
    else return false;
}
