//calculates the ceil of log base2 of (n) : 
//Logic by the time 2^cnt>n check is done , cnt is already 1 larger and hence gives the ceil
int ceil_log(int n){
    int cnt=0;
    for(int i=1;i<n;i*=2){
        cnt++;
    }return cnt;
}
