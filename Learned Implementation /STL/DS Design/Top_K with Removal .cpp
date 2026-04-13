struct topk{
    //ds
    multiset<int> low,high;
    int sum=0,k;
    void init(int K){
        k=K;
    }
    void insert(int x){
        high.insert(x);sum+=x;
        if(high.size()>k){
            int temp=*high.begin();
            high.erase(high.find(temp)); sum-=temp;
            low.insert(temp);
        }
    }
    void erase(int x){
        if(low.find(x)!=low.end()){
            low.erase(low.find(x));
        }else if(high.find(x)!=high.end()){
            high.erase(high.find(x));sum-=x;
            while(!low.empty() && high.size()<k){
                int y=*low.rbegin();
                low.erase(low.find(y));
                high.insert(y);sum+=y;
            }
        }
    }
    int getsum(){
        if(high.size()==0) return 0;
        return sum;
    }
};
