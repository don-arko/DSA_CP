//Time Complexity  :  O(√x + logn .logx) = O(√x)
//Constraint       :  x <= 1e12  ,  n <= 1e18 

vector<pair<int,int>> pfact(int x){    //O(√x)
    vector<pair<int,int>> ans;
    for(int i=2;i*i<=x;++i){
        if(x%i==0){
            int cnt=0;
            while(x%i==0){
                x/=i;
                cnt++;
            }ans.push_back({i,cnt});
        }
    }if(x>1) ans.push_back({x,1});
    return ans;
}
int legendre(int p,int n){  //O(log n)  base is p
    int ans=0;
    for(int i=p;i<=n;i*=p){
        ans+=n/i;
    }return ans;
}
int power(int x,int n){            //O(sqrt(x)+logx.logn)
    vector<pair<int,int>> prime=pfact(x);    //O(sqrtx)
    int mini=INT_MAX;
    for(auto p:prime){                        //O(logx.logn)
        mini=min(mini,legendre(p.first,n)/p.second);
    }return mini;
}
