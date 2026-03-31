#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
vector<int> factor[N+1];
void precomepute(){                   // O(NlogN) both TC and SC
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j+=i){
            factor[j].push_back(i);
        }
    }
}
void solve(){                        //O(#div of X)= O(sqrtX)
    int x;cin>>x;
    for(auto d:factor[x]){
        cout<<d<<' ';
    }cout<<endl;
}
signed main(){                        //O(NlogN + T.sqrtN) 
    precompute();                //O(NlogN)
    int t;cin>>t;
    while(t--){                   //O(T.sqrtX)
        solve();
    }
}
