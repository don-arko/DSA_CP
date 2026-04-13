struct dynamic_median{
    //datastructure
    multiset<int> low,high;

    //methods
    void balance(){
        while(low.size()<high.size()){
            int x=*high.begin();
            high.erase(high.find(x));
            low.insert(x);
        }
        while(low.size()>1+high.size()){
            int x=*low.rbegin();
            low.erase(low.find(x));
            high.insert(x);
        }
    }
    void insert(int x){
        if(low.empty())low.insert(x);
        else if(x<=*low.rbegin()) low.insert(x);
        else high.insert(x);
        balance();
    }
    void remove(int x){
        if(low.find(x)!=low.end()) low.erase(low.find(x));
        else if(high.find(x)!=high.end()) high.erase(high.find(x));
        balance();
    }
    int get_median(){
        if(low.empty()) return -1;
        return *low.rbegin();
    }
};
