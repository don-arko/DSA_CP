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
