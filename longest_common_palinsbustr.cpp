#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    bool dp[n][n];
    int ml=1;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    dp[i][i]=1;

    int start=0;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1])
        {
            dp[i][i+1]=1;
            start=i;
            ml=2;
        }
    }

    for(int k=3;k<=n;k++){
        // focus
        for(int i=0;i<n-k+1;i++){

            int j=i+k-1;
            if(s[i]==s[j] && dp[i+1][j-1]){
                dp[i][j]=1;
                // focus
                if(k>ml){
                start=i;
                ml=k;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    string finstr="";
    for(int i=start;i<ml+start;i++)
    finstr=finstr+s[i];
    cout<<finstr<<endl;
    // OR s.substr(start,ml);
}