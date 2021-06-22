#include <bits/stdc++.h>
#include<cmath>
#include<vector>
#define pb push_back
#define pob pop_back
#define mp make_pair
#define ll long long
#define ld long double
#define ft first
#define sd second
#define pie acos(-1)
#define in(b,a) ( (b).find(a) != (b).end()) 
#define fill(a,v) memset(a, v, a.size())
#define INDEX(arr,ind) (lower_bound(arr.begin(),arr.end(),ind)-arr.begin())

using namespace std;
ll lcm(ll a,ll b){ return (a*b)/__gcd(a,b); }


ll checkprime(ll a){ ll i,b=0; for(i=2;i*i<=a;i++){ if(a%i==0) return 0; } return 1; }
ll sum_digit(ll n){ ll a=0,i; for(i=n;i>0;i=i/10){ a+=(i%10);} return a; }
ll num_digit(ll n){ ll a=0,i; for(i=n;i>0;i=i/10){ a++;} return a; }
ll first_digit(ll n){ ll a=0,i; for(i=n;i>0;i=i/10){ a=i%10;} return a; }

ll get(ll a[],ll i){ ll x=0,j; for(j=i;j>0;j-=j&-j) x+=a[j]; return x; }
ll flip(ll k){ if(k==0) return 1; return 0; }
bool checksum(vector<ll> a,ll sum){ ll i,j,n=a.size(); bool b[n+1][sum+1];  for(i=0;i<=n;i++) b[i][0]=true;  for(i=1;i<=sum;i++) b[0][i]=false;  for(i=1;i<=n;i++){  for(j=1;j<=sum;j++){  if(j<a[i-1]) b[i][j]=b[i-1][j];  else b[i][j]=b[i-1][j] || b[i-1][j-a[i-1]]; } }  return b[n][sum]; } 
    
    int dp[501][501];
    bool ispalin(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])
            return false;
            i++;j--;
        }
        return true;
    }
    int helper(string s, int i, int j){
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        if(i>=j || ispalin(s,i,j))
        return 0;
        
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int tempans=helper(s,i,k)+1+helper(s,k+1,j);
            ans=min(ans,tempans);
        }
        return dp[i][j]=ans;
    }
void solve(){
    string s;
    cin>>s;
    memset(dp,-1,sizeof(dp));
    cout<<helper(s,0,s.size()-1)<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
    solve();
    }	
}