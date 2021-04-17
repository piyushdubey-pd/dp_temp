#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,W;
    cin>>n>>W;
    int dp[n+1][W+1];
    int val[n],w[n];
    for(int &i:val)
    cin>>i;
    for(int &i:w)
    cin>>i;
    for(int i=0;i<=n;i++)
    dp[i][0]=0;
    for(int i=1;i<=W;i++)
    dp[0][i]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(w[i-1]<=j)
            {
                dp[i][j]=max(val[i-1]+dp[i][j-w[i-1]],dp[i-1][j]);
            }
            else
            dp[i][j]=dp[i-1][j];
        }
    } 
    cout<<dp[n][W]<<endl;
}