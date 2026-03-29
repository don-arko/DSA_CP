
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

//Optimised Sieve Code 
vector<int> sieve(int n){
    vector<bool> is_prime(n+1,true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=n;j+=i){
                is_prime[j]=false;
            }
        }
    }return is_prime;
}

//Returning set of primes <=N {Unoptimsed}
vector<int> sieve(int n){
    vector<int> primes;
    vector<bool> is_prime(n+1,true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++){ //loop till n is necessary as loop till root n would only give as primes till sqrt n but we want primes till n
        if(is_prime[i]){
            for(int j=i*i;j++;j+=i){
                primes.push_back(i);
                is_prime[j]=false;
            }
        }
    }
}
