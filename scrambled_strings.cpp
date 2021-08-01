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

unordered_map<string,bool> mamp;
bool helper(string s1, string s2){
    string key=s1+" "+s2;
    if(mamp.find(key)!=mamp.end())
    return mamp[key];
    int n=s1.size();
    if(s1==s2)
    return true;
    if(s1.size()<=1)
    return false;
    bool flag=false;
    for(int i=1;i<s1.size();i++){
        string temp01=s1.substr(0,i); string temp02=s2.substr(0,i);
        string temp11=s1.substr(i,n-i); string temp12=s2.substr(i,n-i);
        string temp21=s1.substr(0,i);string temp22=s2.substr(n-i,i);
        string temp31=s1.substr(i,n-i);string temp32=s2.substr(0,n-i);
        if( (helper(temp01,temp02) && helper(temp11,temp12)) || (helper(temp21,temp22) && helper(temp31,temp32)) ){
        flag= true;
        break;
        }
    }
    return mamp[key]=flag;
}
void solve(){
    string s1,s2;
    cin>>s1>>s2;
    if(s1.length()!=s2.length())
    cout<<false<<endl;

    else{
        cout<<helper(s1,s2)<<endl;
    }
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