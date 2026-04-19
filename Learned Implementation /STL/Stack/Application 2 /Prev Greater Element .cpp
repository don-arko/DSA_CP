//Time Complexity : O(N)
//Classical Implememtation 
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    int a[n];for(int i=0;i<n;i++) cin>>a[i];

    int pge[n];
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]<=a[i]){
            st.pop();
        }
        if(!st.empty()) pge[i]=st.top();
        else pge[i]=-1;
        st.push(i);
    }
    for(auto x:pge) cout<<x<<' ';
}
signed main(){
    solve();
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Time Complexity : O(N)
//Non-Classical Implememtation 
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    int a[n];for(int i=0;i<n;i++) cin>>a[i];

    int pge[n];
    for(int i=0;i<n;i++){
        prev_idx=i-1;
        while(prev_idx>=0 && a[prev_idx]<=a[i]){
            prev_idx=pge[prev_idx];
        }
        pge[i]=prev_idx;
    }
    for(auto x:pge) cout<<x<<' ';
}
signed main(){
    solve();
}
