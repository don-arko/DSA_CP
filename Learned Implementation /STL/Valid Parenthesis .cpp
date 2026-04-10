//Time Complexity : O(n) for all


// for single char type
bool valid(string s){
    int d=0;
    for(char ch:s){
        if(ch=='(')d++;
        else d--;
        if(d<0)return false;
    }return (d==0);
}

//for Multiple Char type
bool valid(string s){
    map<char,int> m;
    m['(']=+1;
    m[')']=-1;
    m['{']=+2;
    m['}']=-2;
    m['[']=+3;
    m[']']=-3;

    stack<int> st;
    for(char ch:s){
        int val=m[ch];
        if(val>0){  //opencing braces
            st.push(val);
        }else{
            if(!st.empty() && st.top()+val==0){
                st.pop();
            }else return false;
        }
    }return st.empty();
}

//Count the min #of parenthesis req :

/*IDEA:

only opening parenthesis req is counted while treversing using d<0
while closing parenthesis req is counted at the end using value of d

*/
int cnt_min(string s){
    int d=0,ans=0;
    for(char ch:s){
        if(ch=='(') d++;
        else d--;
        if(d<0) {ans++;d=0;}
    }
    ans+=d;
    return ans;
}
void solve(){
    string s;cin>>s;
    int d=0;
    int ans=0;
    for(char ch:s){
        if(ch=='(') d++;
        else d--;
        if(d<0){
            ans++;d=0;
        }
    }
    if(d!=0)ans+=abs(d);
    cout<<ans<<'\n';
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt;cin>>tt;
    while(tt--){
        solve();
    }
}
