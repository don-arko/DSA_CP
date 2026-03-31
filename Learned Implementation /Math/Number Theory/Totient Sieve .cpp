const int N=1e6;
bool is_prime[N+1];
void sieve(){                        //O(NloglogN)
    for(int i=2;i<=N;i++) is_prime[i]=true;
    for(int i=2;i*i<=N;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=N;j+=i){
                is_prime[j]=false;
            }
        }
    }
}
int phi[N+1];
void totient(){                        //O(NloglogN)
    for(int i=1;i<=N;i++) phi[i]=i;  //handles the base case
    for(int i=2;i<=N;i++){
        if(is_prime[i]){
            for(int j=i;j<=N;j+=i){
                phi[j]-=phi[j]/i;
            }
        }
    }
}
signed main(){
    sieve();
    totient();
}
