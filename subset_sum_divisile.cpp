#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int &i:arr)
    cin>>i;
    int sum=0,count=0;
    for(int i=0;i<n;i++)
    sum+=arr[i];
    int dp[n+1][sum+1];
    for(int i=0;i<=sum;i++)
    dp[0][i]=0;
    for(int i=0;i<=n;i++)
    dp[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j)
            dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    for(int j=1;j<=sum;j++)
    if(dp[n][j]!=0 && j%m==0)
    count+=dp[n][j];
    cout<<count;
}