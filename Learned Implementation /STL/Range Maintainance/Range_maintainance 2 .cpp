#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
#define F first
#define S second
struct range_maintaince{
    //datastructure:
    set<ii> st;
    //methods()
    void fill_range(int l,int r){
        auto it=st.upper_bound({l,1e9});
        if(it!=st.begin()){
            it--; // last range whose start <=l
            if(it->second >= l){ //overlaps
                l=it->first;
                r=max(r,it->second); //if it->second covers entirety of [l,r]
                st.erase(it);
            }
        }
        it=st.upper_bound({r,1e9});
        if(it!=st.begin()){
            it--; //last range whose start <=r
            if(it->second >=r){  //overlap
                r=it->second;
                l=min(l,it->first); //although this would have been covers earlier
                st.erase(it);
            } 
        }
        while(true){
            it=st.lower_bound({l,0});
            if(it==st.end() || it->first>r) break;
            else st.erase(it);
        }
        st.insert({l,r});
    }
    void clear_range(int l,int r){
        auto it = st.upper_bound({l,1e9});
        if(it!=st.begin()){
            it--; //last range whose start <=l
            if(it->second >= r){ // this range covers entire [l,r]
                int lo1=it->first;
                int hi2=it->second;
                int hi1=l;
                int lo2=r;
                st.erase(it);
                st.insert({lo1,hi1});
                st.insert({lo2,hi2});
                return ;
            }
            if(it->second>l){  //proper partial range as proper overlap
                int lo=it->first;
                int hi=l;
                st.erase(it);
                st.insert({lo,hi});
            }
        }

        it=st.upper_bound({r,1e9});
        if(it!=st.begin()){ //
            it--; //last range whose start <=r
            if(it->second >=r){  //overlap -> prpoer partial range
                int lo=r;
                int hi=it->second;
                st.erase(it);
                st.insert({lo,hi});
            }
        }
        //delete the in between ranges
        while(true){
            it=st.lower_bound({l,0});
            if(it==st.end() || it->first >= r) break;
            else st.erase(it);
        }
    }
    bool check_point(int x){
        auto it=st.upper_bound({x,1e9});
        if(it==st.begin()){  //point lies even before first valid range 
            return false; 
        }else{  //∃ a valid range starting on or before x
            it--; //standard method to get last range starting before x
            if(it->second >= x) return true; 
            else return false;
        }
    }
    bool check_range_any(int x,int y){
        auto it=st.upper_bound({x,1e9});
        if(it!=st.end()){  //∃ a range whose start >x 
            if(it->first<=y) {  //∃ a range which starts after x and covers [x,y]
                return true ; 
            }//else case II or III not possible maybe case I true
        }
        return check_point(x); // check if ∃ a range which starts <= x and covers [x,y]
    }
    bool check_range_all(int x,int y){
        auto it=st.upper_bound({x,1e9});
        if(it!=st.begin()){
            it--; //last range whose start <=x
            if(it->second>=y) return true ;
        }
        return false;
    }
    void print_status(){
        cout<<"{";
        for(auto v:st){
            cout<<"("<<v.first<<","<<v.second<<")";
        }cout<<"}";
        cout<<'\n';
    }
};
void solve();
signed main(){
    range_maintaince rm;
    rm.fill_range(1,4);
    rm.fill_range(2,8);
    rm.fill_range(10,13);
    rm.print_status();
    rm.clear_range(7,11);
    rm.print_status();
    rm.clear_range(1,13);
    rm.print_status();
}
