
//BASIC Sieve Code
const int N=1e7;
bool is_prime[N+1];
void sieve(){
    for(int i=2;i<=N;++i) is_prime[i]=true;
    for(int i=2;i<=N;i++){
        if(is_prime[i]){
            for(int j=2*i;j<=N;j+=i){
                is_prime[j]=false;
            }
        }
    }
}
