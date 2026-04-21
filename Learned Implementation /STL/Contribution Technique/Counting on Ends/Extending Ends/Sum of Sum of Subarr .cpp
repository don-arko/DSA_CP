//Problem         : Sum of ( Sum of Subarray ) ∀ subarr ∈ arr

//Time Complexity : O(N)

int sum=0;
int prev=0;
//traverse the ends
for(int i=0;i<n;i++){
    prev=prev+(i+1)*a[i];   //extending ends to get the ans for curr end
    sum+=prev;
}
cout<<sum<<'\n';
