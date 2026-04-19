#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;cin>>s;
    int n=s.size(),k;cin>>k;
  
    vector<char> v;
    for(int i=0;i<n;i++){
        while(!v.empty() && (s[i]<v.back() && (v.size()+((n-1)-i))>=k)){   //DS.size() ; size after s[i] replaces v.back() rem elemets after i = (n-1)-i , sum of these 2 together must be atleast k
            v.pop_back();
        }
        v.push_back(s[i]);
    }
  
    // len(DS) >= k so print only the first k 
    for(int i=0;i<k;i++)cout<<v[i]<<' ';
    cout<<'\n'; 
}
signed main(){
    solve();
}
