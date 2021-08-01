int dp[1001][1001];
bool helper(string s1, string s2){
    int n=s1.size(),m=s2.size();
    if(dp[n][m]!=-1)
    return dp[n][m];
    if(s1==s2)
    return dp[n][m]=true;
    if(s1.size()<=1)
    return dp[n][m]=false;

    for(int i=1;i<s1.size();i++){
        string temp01=s1.substr(0,i); string temp02=s2.substr(0,i);
        string temp11=s1.substr(i,n-i); string temp12=s2.substr(i,n-i);
        string temp21=s1.substr(0,i);string temp22=s2.substr(n-i,i);
        string temp31=s1.substr(i,n-i);string temp32=s2.substr(0,n-i);
        if( (helper(temp01,temp02) && helper(temp11,temp12)) || (helper(temp21,temp22) && helper(temp31,temp32)) ){
        return dp[n][m]=true;
        break;
        }
    }
}
void solve(){
    string s1,s2;
    cin>>s1>>s2;
    if(s1.length()!=s2.length())
    cout<<false<<endl;

    else{
        memset(dp,-1,sizeof(dp));
        cout<<helper(s1,s2)<<endl;
    }
}