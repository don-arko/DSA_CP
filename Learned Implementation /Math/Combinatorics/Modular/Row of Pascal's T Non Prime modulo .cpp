//Time Complexity : O(N^2) + O(T*n)
//Constraint : n<=1e3 , T<=1e3;
#define int long long int
const int MOD=1e9;          //(Non prime : division not allowed as inv doesn't always exists)
//Use Pascal's Formula to precompute Pascal's Triangle as it is based on Modular Summation and No division Involved
//C(n,r)=C(n-1,r)+C(n-1,r-1);
const int N=1e3;
int nCr[N+1][N+1];
void precompute(){              //O(N^2)
    nCr[0][0]=1;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=i;j++){
            if(j==0) nCr[i][j]=1; // first col of any row =1
            else{
                nCr[i][j]=(nCr[i-1][j]+nCr[i-1][j-1])%MOD; //never out of bounds as we start from i>=1 and j>=1
            }
        }
    }
}
void print(int n){
    for(int j=0;j<=n;j++){
        cout<<nCr[n][j]<<' ';
    }
}
