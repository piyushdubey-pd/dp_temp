#include <bits/stdc++.h>
using namespace std;
int main(){
    string x,y;
    cin>>x>>y;
    int n=x.size(),m=y.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    dp[i][0]=0;
    for(int i=0;i<=n;i++)
    dp[0][i]=0;
    int result=INT_MIN;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
                result=max(result,dp[i][j]);
            }
            else
            dp[i][j]=0;
        }
    }
    cout<<result<<endl;
}