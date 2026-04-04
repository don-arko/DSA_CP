/*
A Row of Pascal's Triangle : nC0  nC1  .......  nCn

Recurrence Relation : C(n,i+1)=C(n,i)*(n-i)/(i+1); //we can start calculating from nC1 using nC0
*/


//Implementation 1
int n;cin>>n;
int ans=1; //nC0=1
cout<<ans<<" ";                 //printing nC0
//calculates nC1,nC1,....nCn
for(int i=0;i<n;i++){           //printting the rem terms
    ans=(ans*(n-i))/(i+1);        //calculates C(n,i+1)
    cout<<ans<<'\n';
}
