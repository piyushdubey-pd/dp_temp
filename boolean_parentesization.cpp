#include<bits/stdc++.h>
using namespace std;   
   
   int helper(string s,int i, int j, int flag){
        if(i==j)
        {
            if(flag)
            return s[i]=='T';
            else
            return s[i]=='F';
        }
        if(i>j)
        return 1;
        
        int ans=0;
        for(int k=i+1;k<j;k=k+2){
            
        int lf=helper(s,i,k-1,0);
        int lt=helper(s,i,k-1,1);
        int rf=helper(s,k+1,j,0);
        int rt=helper(s,k+1,j,1);

        if(s[k]=='|')
        {
            if(flag)
            ans=ans+((lf*rt)+(rf*lt)+(rt*lt));
            else
            ans=ans+(lf*rf);
        }
        if(s[k]=='&')
        {
            if(flag)
            ans=ans+(rt*lt);
            else
            ans=ans+((lf*rt)+(rf*lt)+(rf*lf));
        }
        if(s[k]=='^')
        {   
            if(flag)
            ans=ans+((rt*lf)+(rf*lt));
            else
            ans=ans+((rt*lt)+(rf*lf));
        }
        }
        return ans;
    }
    int main(){
        string s;
        cin>>s;
        cout<<helper(s,0,s.size()-1,1);
        }