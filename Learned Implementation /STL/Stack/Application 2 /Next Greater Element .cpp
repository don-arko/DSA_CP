//Classical Implementation Using Stack 
//Time Complexity : O(N)

#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;int a[n];for(int i=0;i<n;i++)cin>>a[i];

    stack<int> st;
    int nge[n];
    for(int i=n-1;i>=0;--i){
        while(!st.empty() &&  a[st.top()]<=a[i]){
            st.pop();
        }
        if(st.empty()) nge[i]=n;
        else nge[i]=st.top();
        st.push(i);
    }
    for(auto x:nge) cout<<x<<' ';
}
signed main(){
    solve();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------


//Non Classical Implementation without using stack 
//Time Complexity : O(N)
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;int a[n];for(int i=0;i<n;i++)cin>>a[i];
    int nge[n];
    for(int i=n-1;i>=0;--i){
        int next_idx=i+1;
        while(next_idx<n && a[next_idx]<=a[i]){
            next_idx=nge[next_idx];
        }
        nge[i]=next_idx;
    }
    for(auto x:nge)cout<<x<<' ';
}
signed main(){
    solve();
}
