#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mod=1000007;

int main(){
    string s,t;
    cin>>s>>t;

    vector<ll> dp(t.size()+1,0),dp2(t.size()+1,0);

    dp[t.size()]=1; dp2[t.size()]=1;

    for(ll i=s.size()-1;i>=0;i--)
    {
        for (ll j=t.size()-1;j>=0;j--){
            dp2[j]=dp[j];
            if(s[i]==t[j]){
                dp2[j]= (dp[j]+dp[j+1])%mod;
            }
        }
        dp=dp2;
    }
    cout<< dp[0];
}