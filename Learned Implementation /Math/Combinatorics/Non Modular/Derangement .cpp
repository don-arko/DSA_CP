//Time Complexity : O(MAX) or O(n)
//Constraint : n<=20   //since D(22) overflows LL
const int N=20;
int der[N+1];
void precompute(){
    der[0]=1;der[1]=0;
    for(int i=2;i<=N;i++){
        der[i]=(i-1)*(der[i-1]+der[i-2]);
    }
}


//Time Complexity : O(2^n)
//Time Complexity : n<=20   , due to exponential TC as well as D(22) overflows LL
int derangement(int n){
    if(n==0) return 1;
    if(n==1) return 0;
    return (n-1)*(derangement(n-1)+derangement(n-2));
}
