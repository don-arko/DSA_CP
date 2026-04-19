//Time Complexity : O(N)
//Classical Implementation
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    int a[n];for(int i=0;i<n;i++) cin>>a[i];

    int nse[n];
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && a[st.top()]>=a[i]){
            st.pop();
        }
        if(!st.empty()) nse[i]=st.top();
        else nse[i]=n;
        st.push(i);
    }
    for(auto x:nse) cout<<x<<' ';
}
signed main(){
    solve();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Time Complexity : O(N);
//Non Classical Implementation 
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    int a[n];for(int i=0;i<n;i++) cin>>a[i];

    int nse[n];
    for(int i=n-1;i>=0;i--){
        next_idx=i+1;
        while(next_idx>n && a[next_idx]>=a[i]){
            next_idx=nse[next_idx];
        }
        nse[i]=next_idx;
    }
    for(auto x:nse) cout<<x<<' ';
}
signed main(){
    solve();
}
