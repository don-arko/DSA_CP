//Time Complexity : O(MAX+T)
//Caculates nCr in O(1) per test case for all the testcases
//Constraint : T<=1e6 , n,r<=1e6 ; r<=n
#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int MOD=1e9+7;
const int MAX=1e6;

int fact[MAX+1],inv_fact[MAX+1];

int binpow(int a,int b,int m){             //O(log b)=O(log(MOD))
    a%=m;
    if(b==0) return 1;
    if(b&1) return a*binpow(a,b-1,m)%m;    //=  (a*binpow(a,b-1,m))%m as associativity is left to right
    else {
        int temp=binpow(a,b/2,m)%m;       //asso : left to right 
        return temp*temp%m;               //asso : left to right 
    }   
}

void factorials(){                        //O(MAX)
    fact[0]=1;
    for(int i=1;i<=MAX;i++){
        fact[i]=i*fact[i-1]%MOD; //asso : left to right and the product <=1e15 hence wont overflow
    }
    inv_fact[MAX]=binpow(fact[MAX],MOD-2,MOD);
    for(int i=MAX-1;i>=0;--i){
        inv_fact[i]=(i+1)*inv_fact[i+1]%MOD;        //asso: left to right and the produce <=1e15 hence wont overflow
    }
}

int nCr(int n,int r){   //O(1) using precomputed factorials and their inverses
    if(r>n) return 0;
    return fact[n]*(inv_fact[r]*inv_fact[n-r]%MOD)%MOD;    //= (fact[n]*((inv_fact[r]*inv_fact[n-r])%MOD))%MOD  as Asso: left to right
}

signed main(){                  //O(T+MAX)
    int t;cin>>t;
    factorials();               //O(MAX)
    while(t--){             
        int n,r;cin>>n>>r;
        cout<<nCr(n,r)<<'\n';   //O(1)
    }
}
