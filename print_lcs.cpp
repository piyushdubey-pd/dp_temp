#include <bits/stdc++.h>
using namespace std;
int main(){
    string x,y;
    cin>>x>>y;
    int m=x.size(),n=y.size();
    int dp[m][n];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(x[i-1]==y[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i=m,j=n;
    string s="";
    while(i>0 && j>0){
        if(x[i-1]==y[j-1])
        {
            s=x[i-1]+s;
            i--;j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            i--;
            else
            j--;
        }
    }
    cout<<s<<endl;
}