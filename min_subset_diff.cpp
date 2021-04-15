#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,range=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        range+=arr[i];
    }
    bool dp[n+1][range+1];
    for(int i=0;i<=n;i++)
    dp[i][0]=true;
    for(int i=1;i<=range;i++)
    dp[0][i]=false;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=range;j++)
        {
            if(arr[i-1]<=j)
            dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j];
        }

    }
    vector<int> num;
    for(int i=0;i<=range/2;i++)
    {
    if(dp[n][i])
    num.push_back(i);
    }
    int mn=INT_MAX;
    for(int i=0;i<num.size();i++)
    mn=min(mn, (range-(2*num[i])));
    cout<<mn;
}