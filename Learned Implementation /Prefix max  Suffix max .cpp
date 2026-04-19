//Prefix Max

pmax[0]=a[0];
for(int i=1;i<n;i++){
    pmax[i]=max(p[i-1],a[i]);
}

//Suffix Max

pmax[0]=a[n-1];
for(int i=n-1;i>=0;i--){
    pmax[i]=max(p[i+1],a[i]);
}
