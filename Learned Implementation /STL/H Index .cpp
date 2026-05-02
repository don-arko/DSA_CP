/*
  Problem : After Each book Alice Read tell the largest integer B ; Alice has read B books with atleast B pages
*/

//Approach 1      : Data structure Design ; Ds that maintains books with pages > cur b 
//Time Complexity : O(NlogN) 

#include<bits/stdc++.h>
using namespace std;
struct Ds{
    //Datastructures
    multiset<int> m; //contains books with pages > curr b
    int b=0;
    //methods
    void insert(int p){
        if(p>b) m.insert(p);
        while(!m.empty() && *m.begin()<=b) m.erase(m.begin());

        //now m only only contains books with pages > curr b
        //if # such books is now b+1 then we can increase our b
        // as all books has atleast b+1 pages
        if(m.size()>b) b++;
    }
    int get_b(){
        return b;
    }
};
void solve(){
    int n;cin>>n;
    Ds d;
    for(int i=0;i<n;i++){
        int p;cin>>p;
        d.insert(p);
        cout<<d.get_b()<<' ';
    }
    cout<<'\n';
}
signed main(){
    int t;cin>>t;
    while(t--)solve();
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------


//Approach 2      : Freq Array with Cnt Variable : this variable directly maintains the cnt of books with pages > b
//Time Complexity : O(N) 

#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    int freq[100100]={0};
    int cnt=0; //count of books with pages > curr b read so far 
    int b=0;   //largest b ; b books with atleast b pages are read so far
    for(int i=0;i<n;i++){
        int p;cin>>p;

        //maintain cnt 
        freq[p]++; //helps in cnt maintainance
        if(p>b) cnt++;

        if(cnt>b){   //with the inc of this book i have read exactly b+1 books with atleast b+1 pages hence can increase the B val to B+1
            b++;
            cnt-=freq[b]; //update cnt as b has increased reduce #books that are no longer with pages > new b
        }

        cout<<b<<' ';
    }cout<<'\n';
}
signed main(){
    int t;cin>>t;
    while(t--)solve();
}
