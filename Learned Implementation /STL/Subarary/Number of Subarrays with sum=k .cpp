#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,x;cin>>n>>x;
    int p[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
        if(i)p[i]+=p[i-1];
    }
    map<int,int> m;
    int sum=0;
    m[0]++; // to complete the psum array 
    for(int i=0;i<n;i++){   
        sum+=m[p[i]-x];
        m[p[i]]++;
    }cout<<sum<<'\n';
}
signed main(){
    int t;cin>>t;
    while(t--) solve();
}
