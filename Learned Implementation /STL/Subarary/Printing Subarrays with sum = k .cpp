#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,x;cin>>n>>x;
    int p[n];
    //converting the normal array into psum
    for(int i=0;i<n;i++){
        cin>>p[i];
        if(i)p[i]+=p[i-1];
    }
    map<int,vector<int>> m; //instead of freq of tar it now stores pos of targets 
    int sum=0;
    m[0].push_back(-1); // pos of element 0 is -1   // this step is very important
    for(int i=0;i<n;i++){   
        sum+=m[p[i]-x].size();
        for(auto v:m[p[i]-x]){ // all valid l-1 's that can pair up with i
            cout<<"["<<v+1<<","<<i<<"]\n";
        }
        m[p[i]].push_back(i); // push the position for curr element
    }cout<<sum<<'\n';
}
signed main(){
    int t;cin>>t;
    while(t--) solve();
}
