struct multiset_cut{
    //Datastructures
    multiset<int> left,right;

    //methods
    void balance(){
        while(left.size()<right.size()){
            int x=*right.begin();
            right.erase(right.find(x));
            left.insert(x);
        }
        while(left.size()>1+right.size()){
            int x=*left.rbegin();
            left.erase(right.find(x));
            right.insert(x);
        }
    }
    void insert(int x){
        if(left.empty())left.insert(x);
        else if(x<=*left.rbegin()) left.insert(x);
        else right.insert(x);
        balance();
    }
    void remove(int x){
        if(left.find(x)!=left.end()) left.erase(left.find(x));
        else if(right.find(x)!=right.end()) right.erase(right.find(x));
        //else not present
        balance();
    }
    int median(){
        if(left.empty()) return -1;
        return *left.rbegin();
    }
};
