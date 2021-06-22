#include<bits/stdc++.h>
using namespace std;

long long mod=1000000007;
long long dp[1001][801];

    int memoized(int n,int r){
        if(dp[n][r]!=-1)
        return dp[n][r];
        
        if(r==0 || n==r)
        return dp[n][r]=1;
        
        if(r==1)
        return dp[n][r]=n%mod;
        
        return dp[n][r]=(memoized(n-1,r)+memoized(n-1,r-1))%mod;
    }
    int topdown(int n, int r){
        for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
 
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%mod;
        }
        }
        return dp[n][r];
    }

int main(){
    memset(dp,-1,sizeof(dp));
    int n,r;
    cin>>n>>r;
    if(r>n)
    cout<<0<<endl;
    else{
    cout<<topdown(n,r)<<endl;
    cout<<memoized(n,r)<<endl;
    }
}