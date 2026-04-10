
//Time Complexity : O(NlogK)
void solve(){
    int n,k;cin>>n>>k; int a[n];
    for(int i=0;i<n;i++)cin>>a[i];

    multiset<int> m;
    for(int i=0;i<n;i++){
        m.insert(a[i]);
        if((i-k)>=0) m.erase(m.find(a[i-k])); //delete 1 occ of a[i] i.e. the first one
        if(i>=k-1) cout<<*m.begin()<<' '; //i>=k-1 means we form now every i gives a window of size , so prints its minimum
    }

}
//Monotone Deque Solution : Classical Interview Question
//Time Complexity : O(N) 
struct monotone_deque{
    deque<int> dq;
    void insert(int x){
        while(!dq.empty() && dq.back()>x) dq.pop_back();
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
void solve(){
    int n,k;cin>>n>>k; int a[n];
    for(int i=0;i<n;i++)cin>>a[i];

    monotone_deque m;
    for(int i=0;i<n;i++){    //O(N)
        m.insert(a[i]);      //O(1) {amortized}
        if((i-k)>=0) m.remove(a[i-k]); //delete 1 occ of a[i] i.e. the first one      //O(a)
        if(i>=k-1) cout<<m.getmin()<<' '; //i>=k-1 means we form now every i gives a window of size , so prints its minimum     //O(1)
    }
}
