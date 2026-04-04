//Time Complexity : O(logx) 
 
//Definition : ⌈logx⌉ = min{k | 2^k>=x}
int ceil_log(int n){
    int k=0;
    for(int i=1;i<n;i*=2){ // here  i=2^k is checked if i <x it is incremented 
        k++;
    }
    //loop fails at 2^k>=k which is the mean k req
    return k;
}



//Definition : ⌊logx⌋ = max{k | 2^k <=x}
int floor_log(int x){
    int k = 0;
    while((1 << (k + 1)) <= x){
        k++;
    }
    //loop fails at 2(k+1) >k which means 2^k <= x is the max k
    return k;
}
