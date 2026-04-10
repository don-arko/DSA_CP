//With Queries                    Time Complexity : O(NlogN+QlogN) 
//                                  Constraint    :  N,Q <= 1e6  , a[i]<=1e9                                     

#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
    //inputs
    int n,q;cin>>n>>q;
    int a[n];for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n); //min price item first
  
    //psum re-arrangment
    for(int i=1;i<n;i++){
        a[i]+=a[i-1];
    }
    //now element at each pos tells the B req to buy all element till that point
    //for each B we req #elements <=B  -> direct use case of Upperbound
    while(q--){
        int x;cin>>x;
        cout<<upper_bound(a,a+n,x)-a<<'\n';
    }
}
signed main(){
    solve();
}
