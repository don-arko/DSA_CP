//Time Complexity : O(logx) 
 
//Definition : ⌈logx⌉ = min{k | 2^k>=x}
int ceil_log(int x){
     int k=0;
    while(1<<(k)<x){
        k++;
    }//loop fails when 2^k>=x which is the first k hence min k
    return k;
}
//alternate implementation with for loop
int ceil_log(int x){
    int k=0;
    for(int i=1;i<x;i*=2){ // here  i=2^k is checked if i <x it is incremented 
        k++;
    }
    //loop fails at 2^k>=x which is the mean k req
    return k;
}

//Definition : ⌊logx⌋ = max{k | 2^k <=x}
int floor_log(int x){
    int k = 0;
    while((1 << k) <= x){   
        k++;
    }
    //loop fails at 2^k >x which means prev value i.e. k-1 is the max k ; 2^k<= x 
    return k-1; //if it fails at k=0 which means x < 1 (= 2^0) ; then k-1=-1 returned which won;t happen as x>=1 is always given as input
}
//alternate implementation with for loop
int floor_log(int x){
    int k=0;
    for(int i=1;i<=x;i+=i){
        k++;
    }
    //loop fails at 2^k > x which means prev value of k was the last value ; 2^k <=x 
    return k-1;
}
