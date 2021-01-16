#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int dp[1000][1000];

int knapsack(vector <int> wt,vector <int> val, int W, int n){
    if(n==0 || W==0)
    return 0;
    if(dp[n][W]!=-1)
    return dp[n][W];
    else{
        if(wt[n-1]<=W)
        return dp[n][W]=max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt, val, W, n-1));
        else
        return dp[n][W]=knapsack(wt,val,W,n-1);
    }
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    vector <int> wt(n);
    vector <int> val(n);
    int W;
    cin>>n>>W;
    for(int i=0;i<n;i++)
    cin>>wt[i];
    for(int i=0;i<n;i++)
    cin>>val[i];
    cout<<knapsack(wt,val,W,n);
}
