//Recursive Implementation of GCD  , Time Complexiy: O(log(min(a,b)))

int gcd(int a,int b){   //first arg is always larger imp
    if(b==0) return a;
    else return gcd(b,a%b); 
}
int gcd1(int a,int b){  //second arg is always larger imp
    if(a==0) return b;
    else return gcd1(b%a,a);
}


//One Liner , Time Complexiy: O(log(min(a,b)))

int gcd(int a,int b){
    return (b)?gcd(b,a%b):a;
}

//Iterative Implementation of GCD , Time Complexity : 
int gcd(int a,int b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}
