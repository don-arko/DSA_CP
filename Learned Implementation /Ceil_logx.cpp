//calculates the ceil of log base2 of (n) : 
//Def of Ceil(log x): min k ; 2^k>=x

int ceil_log(int n){
    int cnt=0;
    for(int i=1;i<n;i*=2){
        cnt++;
    }return cnt;
}
