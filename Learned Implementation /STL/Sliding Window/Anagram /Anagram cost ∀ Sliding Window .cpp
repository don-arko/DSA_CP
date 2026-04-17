/*
Problem : Given two string S,T;|S|>|T| . Find the cost to make every |T| len window of S anagram of T
          |S|=n
          |T|=m
*/


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Approach 1:  Basic Bruteforce : 
Time Complexity : O(nmlog26)
*/

#include<bits/stdc++.h>
using namespace std;
string s,t;
int n,m;
int cost(int start){        //O(mlog26)
    //datastructures
    map<int,int> freq_s,freq_t;

    for(int i=start;i<start+m;i++) freq_s[s[i]-'a']++;  //O(mlog26)
    for(int i=0;i<m;i++) freq_t[t[i]-'a']++;            //O(mlog26)

    //cost calculation 
    int sum=0;
    for(auto v:freq_s){                      //O(26log26)
        // if(v.second>freq_t[v.first]){
        //     sum+=(v.second-freq_t[v.first]);
        // }
        sum+=max(0,v.second-freq_t[v.first]);  //O(log26)
    }
    return sum;
}
void solve(){
    cin>>s>>t;
    map<int,int> freq_s,freq_t;
    n=s.length();
    m=t.length();

    //traverse all the n-m+1 subarrays 
    //iterate over the start for all sub array
    for(int i=0;i<n-m+1;i++){                   //TC=O(n*mlog26)
        cout<<cost(i)<<' ';
    }
    
    
}
signed main(){
    solve();
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------


/*
Approach 2 : Optimisation not , building the freq map for each window 
Time Complexity : O(26*N*log26)
*/
#include<bits/stdc++.h>
using namespace std;

int cost(map<int,int> m1,map<int,int> m2){   //O(26log26)
    int sum=0;
    for(auto v:m1){
        sum+=max(0,v.second-m2[v.first]);          //O(log26)
    }
    return sum;
}
void solve(){
    string s,t;
    cin>>s>>t;
    map<int,int> freq_s,freq_t;
    int n=s.length();
    int m=t.length();

    for(auto ch:t)freq_t[ch-'a']++; //const freq array 
    //Standard SW Template 
    for(int i=0;i<n;i++){                   //O(26*n*log26)
        //insert
        freq_s[s[i]-'a']++;                  //O(log26)
        
        //erase
        if(i-m>=0){
            freq_s[s[i-m]-'a']--;             //O(log26)
        }
        //get query
        if(i>=m-1){
            cout<<cost(freq_s,freq_t)<<' ';    //O(26log26)
        }
    }
        
    
    
}
signed main(){
    solve();
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------


/*
Approach 3 : Optimisation use array and remove the log factor to const
Time Complexity : O(26*N)
*/

#include<bits/stdc++.h>
using namespace std;
int cost(int a[],int b[]){
    int sum=0;
    for(int i=0;i<26;i++){
        sum+=max(0,a[i]-b[i]);
    }
    return sum;
}
void solve(){
    string s,t;cin>>s>>t;
    int n=s.size();
    int m=t.size();
    int freq_s[26]={0};
    int freq_t[26]={0};
    for(char ch:t)freq_t[ch-'a']++;
    //std template for SW
    for(int i=0;i<n;i++){            //O(26 * N)
        //insert()
        freq_s[s[i]-'a']++;                 // O(1)
        
        //erase()
        if(i-m>=0) freq_s[s[i-m]-'a']--;      //O(1)

        //cost
        if(i>=m-1)
            cout<<cost(freq_s,freq_t)<<' ';                    //O(26)
    }
}
signed main(){
    solve();
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------


/*
Approach 4: Optimisation , remove the 26 factor which is the size of the DS
Time Complexity : O(N)
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> const_freq(26,0); //freq array for the chars in string t


struct Ds{
    //Data structure
    int freq[26]={0}; // vector<int> freq(26,0) won't work inside struct
    int cost=0; //maintains the curr cost
    //behaves as freq array for every m len window of string S

    //methods
    void insert(char ch){    //O(1)
        cost-=max(0,freq[ch-'a']-const_freq[ch-'a']); //remove the prev contribution of ch from prev ans
        freq[ch-'a']++;                               //update the freq of ch
        cost+=max(0,freq[ch-'a']-const_freq[ch-'a']); //add the new contribution to ans
    }
    void erase(char ch){     //O(1)
        cost-=max(0,freq[ch-'a']-const_freq[ch-'a']); //remove the prev contribution of ch from prev ans
        freq[ch-'a']--;                               //update the freq of ch
        cost+=max(0,freq[ch-'a']-const_freq[ch-'a']); //add the new contribution to ans
    }
    int getcost(){          //O(1)
        return cost;
    }
};


void solve(){
    string s,t;cin>>s>>t;
    int n=s.length();
    int m=t.length();
    
    //build freq array for T
    for(char ch:t){
        const_freq[ch-'a']++;
    }

  
    Ds d;
    //standard SW Template
    for(int i=0;i<n;i++){
        //insert
        d.insert(s[i]);
        //erase
        if(i-m>=0){
            d.erase(s[i-m]);
        }
        if(i>=m-1){
            cout<<d.getcost()<<' ';
        }
    }
}
signed main(){
    solve();
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
