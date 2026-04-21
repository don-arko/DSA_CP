//Time Complexity : O(N)

int sum=0;
//traverse the atomic items
for(int i=0;i<n;i++){
    int c=(i+1)*(n-i); // #subarrays/rows containing arr[i] is the contribution of arr[i] to req sum
    sum+=c*a[i];
}
cout<<sum<<'\n';   
