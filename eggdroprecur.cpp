
// *******done with bin search******
#include <bits/stdc++.h>
#include<cmath>
#include<vector>
//#include <boost/multiprecision/cpp_int.hpp>
#define pb push_back
#define pob pop_back
#define mp make_pair
#define ll long long
#define lll cpp_int
#define ld long double
#define ft first
#define sd second
#define pie acos(-1)
#define in(b,a) ( (b).find(a) != (b).end()) 
#define fill(a,v) memset(a, v, a.size())
#define INDEX(arr,ind) (lower_bound(arr.begin(),arr.end(),ind)-arr.begin())
//using namespace boost::multiprecision;
using namespace std;
ll lcm(ll a,ll b){ return (a*b)/__gcd(a,b); }
ll checkprime(ll a){ ll i,b=0; for(i=2;i*i<=a;i++){ if(a%i==0) return 0; } return 1; }
ll sum_digit(ll n){ ll a=0,i; for(i=n;i>0;i=i/10){ a+=(i%10);} return a; }
ll num_digit(ll n){ ll a=0,i; for(i=n;i>0;i=i/10){ a++;} return a; }
ll first_digit(ll n){ ll a=0,i; for(i=n;i>0;i=i/10){ a=i%10;} return a; }
ll get(ll a[],ll i){ ll x=0,j; for(j=i;j>0;j-=j&-j) x+=a[j]; return x; }
ll flip(ll k){ if(k==0) return 1; return 0; }
bool checksum(vector<ll> a,ll sum){ ll i,j,n=a.size(); bool b[n+1][sum+1];  for(i=0;i<=n;i++) b[i][0]=true;  for(i=1;i<=sum;i++) b[0][i]=false;  for(i=1;i<=n;i++){  for(j=1;j<=sum;j++){  if(j<a[i-1]) b[i][j]=b[i-1][j];  else b[i][j]=b[i-1][j] || b[i-1][j-a[i-1]]; } }  return b[n][sum]; } 
ll mod=1000000007;
int dp[201][201];
    int egg(int n, int k) 
    {
        if(n==1 || k<=1)
        return k;
        
        if(dp[n][k]!=-1)
        return dp[n][k];
        int ans=INT_MAX;
        int lb=1,ub=k;
        while(lb<=ub){
        int mid=(lb+ub)/2;
        int left=egg(n-1, mid-1);
        int right=egg(n, k-mid);
        int temp=1+max(left,right);
        if(left<right)
        lb=mid+1;
        else
        ub=mid-1;
        ans=min(ans,temp);
    }
    return dp[n][k]=ans;
    }
    void solve(){
        int n,k;
        cin>>n>>k;
        memset(dp,-1,sizeof(dp));
        cout<< egg(n,k);
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