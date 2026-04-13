#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,q;cin>>n>>q;
    int l[n],r[n];
    for(int i=0;i<n;i++){
        cin>>l[i]>>r[i];
    }
    sort(l,l+n);sort(r,r+n);
    while(q--){
        int x;cin>>x;
        //ans = #segs not covering point x
        int ans=lower_bound(r,r+n,x)-r;   //#R's < x 
        ans+=(l+n)-upper_bound(l,l+n,x);  //#L's > x
        cout<<n-ans<<'\n';
    }
}
signed main(){
    solve();
}
