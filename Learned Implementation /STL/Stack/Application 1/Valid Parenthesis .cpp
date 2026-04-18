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
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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


