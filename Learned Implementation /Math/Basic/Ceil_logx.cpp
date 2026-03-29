//calculates the ceil of log base2 of (n) : 
//Def of Ceil(log x): min k ; 2^k>=x

int ceil_log(int n){
    int k=0;
    for(int i=1;i<n;i*=2){ // here  i=2^k is checked if i <x it is incremented 
        k++;
    }return k;
}
