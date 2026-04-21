//Problem         : Sum of (Product of Subarray) ∀subarr ∈ arr
//Time Complexity : O(N)

/*
Idea : Here since the operations are ∑ ∏ which are hetero-geneous hence the contribution of atmoic item is no longer independent it depends on presence of other item in 
       the Subarray
Use extending item Contribution on ends i.e. calculate the ans for curr end by extending the prev end : 

*/

int sum=0;
int prev=0;
//traverse the ends
for(int i=0;i<n;i++){
    prev=prev*a[i]+a[i];   //extending ends to get the ans for curr end
    sum+=prev;
}
cout<<sum<<'\n';
