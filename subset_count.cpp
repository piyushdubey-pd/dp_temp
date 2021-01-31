#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,W;
    cin>>n>>W;
    int arr[n];
    for(int &i:arr)
    cin>>i;
    int dp[n+1][W+1];
    for(int i=0;i<=W;i++)
    dp[0][i]=0;
    for(int i=0;i<=n;i++)
    dp[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(arr[i-1]<=j)
            dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][W];
}