struct topk{
    //ds
    priority_queue<int> pq; //to be used as min heap
    int sum=0,k;
    void init(int K){
        k=K;
    }
    void insert(int x){
        pq.push(-x);
        sum+=x;
        if(pq.size()>k){
            sum-=-pq.top();
            pq.pop();
        }
    }
    int getsum(){
        return sum;
    }
};
