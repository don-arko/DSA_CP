//Time Complexity :  O(√x + log x) = O(√x)
//Constraint      :  n <= 1e12
vector<pair<int,int>> pfact(int x){    //O(√x)
    vector<pair<int,int>> ans;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            int cnt=0;
            while(x%i==0){
                x/=i;cnt++;
            }
            ans.push_back({i,cnt});
        }
    }
    if(x>1) ans.push_back({x,1});
    return ans;
}
int cnt_div(int x){
    auto prime=pfact(x);                //O(√x)
    int d=1;
    for(auto p:prime){                  //O(logx)
        d*=(1+p.second);
    }return d;
}
