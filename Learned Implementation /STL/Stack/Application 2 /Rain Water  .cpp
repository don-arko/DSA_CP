//Approach 1 : Summation of Horizontal Strips {Using stack }
#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
    int n;cin>>n;
    int h[n];for(int i=0;i<n;i++)cin>>h[i];

    int ar=0;
    stack<int> st; //monotonic decreasing maintaining valley
    for(int i=0;i<n;i++){
        while(!st.empty() && h[i]>h[st.top()]){ //i acts as RB for curr top as h[i]>h[top]
            int base=st.top();
            st.pop();
            if(st.empty()){         //no LB
                break;
            }
            //∃ both LB and RB 
            //compute area
            int w=i-st.top()-1; // LB=st.top(),RB=i
            int hi=min(h[i],h[st.top()])-h[base];
            ar+=w*hi;
        } 
        // h[i] <= h[top] i is not a RB hence valley continues
        st.push(i);
    }
    cout<<ar<<'\n';
    
}
signed main(){
    int t;cin>>t;
    while(t--)solve();
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------



//Approach 2 : Summation of Vertical Strips {Using Prefix Max and Suffix Max}
#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
    int n;cin>>n;
    int a[n];for(int i=0;i<n;i++) cin>>a[i];
  
    int pmax[n];pmax[0]=a[0];
    for(int i=1;i<n;i++){
        pmax[i]=max(pmax[i-1],a[i]);
    }
    int smax[n];smax[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        smax[i]=max(smax[i+1],a[i]);
    }
  
    int sum=0;
    for(int i=0;i<n;i++){
        // if(a[i]<pmax[i] && a[i]<smax[i]){ 
        //     sum+=min(pmax[i]-a[i],smax[i]-a[i]);
        // }
        sum+=min(pmax[i],smax[i])-a[i];        // left term is always >= right term hence for elements not having boundaries on both side this sum comes to be 0 
    }
    cout<<sum<<'\n';
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt;cin>>tt;
    while(tt--){
        solve();
    }
}
