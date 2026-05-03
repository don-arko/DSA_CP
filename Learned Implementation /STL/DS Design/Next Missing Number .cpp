//Datastructures Requirement 
//i)  Insert(x) : insert  an element into the set
//ii) get(x)    : returns the smallest element >=x not present in the set
struct Ds{
    set<int> s,ns;
    void insert(int x){
        s.insert(x);
        ns.erase(x);
        if(!s.count(x+1))ns.insert(x+1);
    }
    int get(int x){
        if(!s.count(x)) return x;
        else{ //x is present in s 
            //which means its right boundary is present in ns 
            auto it=ns.lower_bound(x+1);
            return *it;
        }
    }
};
