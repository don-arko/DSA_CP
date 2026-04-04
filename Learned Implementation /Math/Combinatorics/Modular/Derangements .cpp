//Time Complexity : O(MAX)
//Constraint <=1e6

#define int long long int
const int MOD=1e9+7;
const int N=1e6;
int der[N+1];
void precompute(){
    der[0]=1;der[1]=0;
    for(int i=2;i<=N;i++){
        der[i]=(i-1)*(der[i-1]+der[i-2]%MOD)%MOD;
    }
}
}
