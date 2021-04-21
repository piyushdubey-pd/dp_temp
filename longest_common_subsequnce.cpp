#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int lcs(int n, int m, string s1, string s2){
    // base condition for any of the strings ending we return 0
    if(n==0 || m==0)
    return 0;
    // for equal char we increase the length of subset by 1
    else if(s1[n-1]==s2[m-1])
    return 1+lcs(n-1,m-1,s1,s2);
    // maximum length is needed
    else
    return max(lcs(n-1,m,s1,s2),lcs(n,m-1,s1,s2));
}

int main(){
    string str,str1;
    cin>>str>>str1;
    cout<< lcs(str.size(),str1.size(),str,str1);
}