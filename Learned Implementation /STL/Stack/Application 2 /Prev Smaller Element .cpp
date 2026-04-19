//Classical Implementation Using Stack 
//Time Complexity : O(N)

#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    int a[n];for(int i=0;i<n;i++)cin>>a[i];
    int pse[n];
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]>=a[i]){
            st.pop();
        }
        if(!st.empty()) pse[i]=st.top();
        else pse[i]=n;
        st.push(i);
    }
    for(auto x:pse) cout<<x<<' ';
    cout<<'\n';
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
    int n;cin>>n;
    int a[n];for(int i=0;i<n;i++)cin>>a[i];
    int pse[n];
    for(int i=0;i<n;i++){
        int pidx=i-1;
        while(pidx>=0 && a[pidx]>=a[i]){
            pidx=pse[pidx];
        }
        pse[i]=pidx;
    }
    for(auto x:pse) cout<<x<<' ';
}
signed main(){
    solve();
}
