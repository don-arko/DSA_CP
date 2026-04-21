//Problem         : Find the sum of pairs ; sum is atleast x and sum is as small as possible 
//Time Compleixty : O(NlogN)


//Idea : Counting on ends using a DS for Prev ends

int ans=1e9;
set<int> st;
//traverse the ends
for(int r=0;r<n;r++){
    auto it = st.lower_bound(x-a[r]); //gives the min a[l] ; a[l]>=x-a[r] => a[l]+a[r] >=x is minimised as a[l] is minimised while a[r] is fixed
    if(it!=st.end()){ // l exists
        ans=min(ans,*it+a[r]);
    }
    st.insert(a[r]);
}
cout<<ans<<'\n';
