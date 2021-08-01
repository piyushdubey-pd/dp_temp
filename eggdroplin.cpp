// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    int egg(int n, int k) 
    {
        if(n==1 || k<=1)
        return k;
        
        if(dp[n][k]!=-1)
        return dp[n][k];
        int ans=INT_MAX;
        for(int i=1;i<=k;i++){
            int left,right;
            if(dp[n-1][i-1]!=-1)
            left=dp[n-1][i-1];
            else
            left=dp[n-1][i-1]=eggDrop(n-1,i-1);
            if(dp[n][k-i]!=-1)
            right=dp[n][k-i];
            else
            right=dp[n-1][k-i]=eggDrop(n,k-i);
            int temp=1+max(left,right);
            ans=min(ans,temp);
        }
        return dp[n][k]=ans;
    }
    int eggDrop(int n, int k){
        memset(dp,-1,sizeof(dp));
        return egg(n,k);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends