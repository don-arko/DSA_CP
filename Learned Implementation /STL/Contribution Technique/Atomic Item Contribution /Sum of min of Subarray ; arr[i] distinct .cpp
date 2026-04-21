//Problem         : Sum of (Minimum of Subarrays) ∀subarrays ∈ arr  {Elements are Distinct}
//Time Complexity : O(N)

//build pse arr ; strictly smaller
int pse[n];
for(int i=0;i<n;i++){
    int p_idx=i-1;
    while(p_idx>=0 && arr[p_idx]>=arr[i]){
        p_idx=pse[p_idx];
    }
    //arr[p_idx] < arr[i] => p_idx is the req index
    pse[i]=p_idx;
}

//build nse arr ; strictly smaller
int nse[n];
for(int i=n-1;i>=0;i--){
    int n_idx=i+1;
    while(n_idx<n && arr[n_idx]>=arr[i]){
        n_idx=nse[n_idx];
    }
    //arr[p_idx] < arr[i] => p_idx is the req index
    nse[i]=n_idx;
}

int sum=0;
//traverse the atomic items i.e. arr[i]
for(int i=0;i<n;i++){
    int c=(i-pse[i])*(nse[i]-i); //#subarrays containing arr[i] as minimum
    sum+=c*arr[i];
}
cout<<sum<<'\n';
