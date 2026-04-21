//Problem         : Find the #pairs whose sum = x
//Time Complexity : O(NlogN)

//Idea : Counting on ends using Ds for prev ends
/*
Ans for the curr end = # pairs(l,r) ending at i i.e. r=i whose sum = x 
                     = freq[x-a[r]] before R 
                     = freq of all prev ends can be maintained in a freq map 
*/

int ans=0;
map<int,int> freq;
//traverse the ends
for(int r=0;r<n;r++){    //O(NlogN)
    ans+=freq[x-a[r]]; //#pairs(l,r) ending at i whose sum=x = freq[x-a[r]]
    freq[a[r]]++;      //update the Ds for the next end
}
cout<<ans<<'\n';
