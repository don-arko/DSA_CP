//Time Complexity    :    O(√x+logx)=O(√x)
//Constraint         :    x <= 1e12
vector<pair<int,int>> pfact(int x){            //O(√x)
    vector<pair<int,int>> ans;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            int cnt=0;
            while(x%i==0){
                x/=i;
                cnt++;
            }ans.push_back({cnt,i});
        }
    }if(x>1)ans.push_back({x,1});
    return ans;
}

int totient(int x){                            //O(√x+logx)=O(√x)
    vector<pair<int,int>> prime=pfact(x);
     //no need to handle x=1 as empty vector is returned in such case and nothing is subtracted from x
    for(auto p:prime){
        x-=x/p.first;
    }return x;
}
