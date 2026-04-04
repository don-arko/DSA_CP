//Time complexity : O(r)
// n,r<=30 

//This method doesn't use factorial and hence avoid overflow
int nCr(int n,int r){
    if(r<0 || r>n) return 0;
    r=min(r,n-r);
    int ans=1; //nC0
    //calculate nC1,nC2,...,nCr using Recurrence Relation C(n,i+1)=C(n,i)* (n-1)/(i+1) 
    for(int i=0;i<r;i++){
        ans=ans*(n-i)/(i+1); //Numerator is always divisible by denominator {Theorem : product of x consecutive nos is always divisble by x!}
                            //Because RHs is nothing but an binomial coeff which is always an integer
    }return ans;
}
