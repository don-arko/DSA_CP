/*
A Row of Pascal's Triangle : nC0  nC1  .......  nCn

Recurrence Relation : nCr=nC(r-1) * (n-r+1)/r
*/


//Implementation 1
int n;cin>>n;
int term=1; //nC0=1
cout<<term<<" ";                 //printing the first term
for(int r=1;r<=n;r++){           //printting the rem terms
    term=term*(n-r+1)/r;         //do not use the shorthand term*=(n-r+1)/r here division happens first which means we get floor division and result is incorrect
    cout<<term<<" ";
}

//Implementation 2
int n;cin>>n;
int term=1; //nC0=1
for(int r=1;r<=n;r++){
    cout<<term<<" ";
    //update ans use r+1 in the rec relation  as r for next term is r+1
    //(n-(r+1)+1)/(r+1) =(n-r)/(r+1)
    term=term*(n-r)/(r+1);         //do not use the shorthand term*=(n-r+1)/r here division happens first which means we get floor division and result is incorrect
    
}
