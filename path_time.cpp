#include <bits/stdc++.h>
using namespace std;

bool flag=false;
void cnter(vector<vector<char>> &arr, int i, int j, int n, int m, int cnt, const int k)
{
    if(i==n-1 && j==m-1 && cnt<=k)
    {
        // cout<<"succ"<<endl;
        flag=true;
        return;
    }
    if(i<0 || j<0 || i>=n || j>=m)
    {
        // cout<<"case1 "<<i<<" "<<j<<endl;
       return; 
    }
    if(arr[i][j]=='#')
    return;


    if(arr[i][j]=='.'){
        // cout<<i<<" "<<j<<endl;
        arr[i][j]='#';
        
    cnter(arr,i+1,j,n,m,cnt+1,k);
    cnter(arr,i,j+1,n,m,cnt+1,k);
    cnter(arr,i-1,j,n,m,cnt+1,k);
    cnter(arr,i,j-1,n,m,cnt+1,k);
    }
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<char>> arr(n, vector<char>(m));
    
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>arr[i][j];
    }
    }
    // cout<<endl;
    // for(int i=0;i<n;i++){
    // for(int j=0;j<m;j++){
    //     cout<<arr[i][j]<<" ";
    // }
    // cout<<endl;
    // }
    int cnt=0;

    cnter(arr,0,0,n,m,cnt,k);
    if(flag)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
}