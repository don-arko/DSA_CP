// Problem         : Sum of (sum of triplets) ∀ triplets ∈ arr 
// Time Complexity : O(N)


int nC2(int n){
    return n*(n-1)/2;
}

int sum=0;
//traverse the atomic items arr[i] : O(N)
for(int i=0;i<n;i++){
    int c=nC2(n-1);       //#triplets containing arr[i] is the contribution of arr[i] to req sum
    sum+=c*a[i];
}   
cout<<sum<<'\n';
