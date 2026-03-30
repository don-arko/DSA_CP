//Time Complexity : O(NloglogN + QLogN) 

const int N=1e6;
int spf[N+1];
void precompute(){  //O(NLoglogN) like sieve of eratosthenes
    for(int i=2;i<=N;++i) spf[i]=i;
    for(int i=2;i*i<=N;++i){
        if(spf[i]==i){
            for(int j=i*i;j<=N;j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
}
vector<int> fact_factorisation(int x){        //O(logx) per query or test case
    vector<int> ans;
    while(x>1){
        ans.push_back(spf[x]);
        x/=spf[x];
    }return ans;
}

signed main(){         // O(NloglogN + TlogN)
    precompute();      //O(NloglogN)
    int t;cin>>t;        
    while(t--){        //O(T.logN)
        solve();
    }
}
