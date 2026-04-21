//Problem         : Sum of ( # Inversions in Subarray ) ∀ subarr ∈ arr

//Time Complexity : O(N^2) 

int sum=0;
//traverse the atomic items i.e. inv pairs
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(a[i]>a[j]){  //found a inv pair
            int c=(i+1)*(n-j);      // #subarrays containing the inv pair(i,j) is the contribution of this inv pair to req sum
            sum+=c*1;
        }
    }
}
cout<<sum<<'\n';
