//Approach 1 : Using freq map
//Time Complexity :  O(nlog26)

#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s,t;cin>>s>>t;
    if(s.length()!=t.length()) { cout<<"Not possible";return; }
  
    map<char,int> a,b;
    for(char ch:s)a[ch-'a']++;    //O(nlog26)
    for(char ch:t)b[ch-'a']++;    //O(mlog26)

    //cost = sum of positive diff
    int sum=0;
    for(auto p:a){                      //O(26log26)
        sum+=max(0,p.second-b[p.first]);  //O(log26)
    }
    cout<<sum<<'\n';

}
signed main(){
    solve();
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Approach 2 : Using freq Array
//Time Complexity : O(n+26) 

#include<bits/stdc++.h>
using namespace std;
int a[26],b[26]; //freq array

void solve(){
    string s,t;cin>>s>>t;
    if(s.length()!=t.length()) { cout<<"Not possible";return; }
    
    for(char ch:s)a[ch-'a']++;  //O(n)
    for(char ch:t)b[ch-'a']++;  //O(m)
 
    //cost = sum of positive diff  {as len can't change as operation = transform only }
    int sum=0;
    for(int i=0;i<26;i++){   //O(26)
        sum+=max(0,a[i]-b[i]);
    }
    cout<<sum<<'\n';

}
signed main(){
    solve();
}
