//Monotone Deque Solution : Classical Interview Question
//Time Complexity : O(N) 
struct monotone_deque{
    deque<int> dq;
    void insert(int x){
        while(!dq.empty() && dq.back()>x) dq.pop_back();  //use >  to get maximum in every k len window
        dq.push_back(x);
    }
    void remove(int x){ 
        if(dq.front()==x){  //dq.size()>=1 as min always exist in the dq
            dq.pop_front();
        }
    }
    int getmin(){ 
        return dq.front(); //dq.size()>=1 as min always exists in the dq
    }
};
