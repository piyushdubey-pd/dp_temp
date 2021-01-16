#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll n, y;
    cin>>n>>y;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)
    cin>>arr[i];
    bool dp[n+1][y+1];
    for(ll i=0;i<=n;i++)
    dp[i][0]=true;
    for(ll i=1;i<=y;i++)
    dp[0][i]=false;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=y;j++)
        {
            if(arr[i-1]>j)
            dp[i][j]=dp[i-1][j];
            else{
            dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
            // actually accessing A[i] only just because loop has started from i+1
            }
        }
    }
    cout<<dp[n][y]<<endl;
}