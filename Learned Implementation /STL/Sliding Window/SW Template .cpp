
Ds d;
for(int i=0;i<n;i++){
    d.insert(a[i]);                             //insert the new element into the Data structure
    
    if(i-k>=0) d.erase(a[i-k]);                 //erase the old element from the data structure 
    
    if(i>=k-1) cout<<d.get<<' ';                //query on valid k len window
}
