//Time Complexity : O(NlogMOD)
#define int long long int
const int MOD=1e9+7;    //(prime Modulus : division allowed as inv exists)
void row_pascal(int n){
    int ans=1; //nC0
    cout<<ans<<'\n';
    //calculates nC1,nC2,....nCn
    for(int i=0;i<n;i++){
        ans=(ans*(n-i))%MOD;
        ans=ans*inv(i+1)%MOD;
        cout<<ans<<' ';
    }
}
