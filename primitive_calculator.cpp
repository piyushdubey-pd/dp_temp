#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using std::vector;
using namespace std;

vector<int> min_ops(int n){
  vector<int> a(n+1);
  fill(a.begin(),a.end(),0);
  for(int i=2;i<n+1;i++){
    int min1=a[i-1];
    int min2=INT_MAX;
    int min3=INT_MAX;
    if(i%2==0)
    min2=a[i/2];
    if(i%3==0)
    min3=a[i/3];

   int minOP=min(min1,min(min2,min3));
    a[i]=minOP+1;
  }
    return a;
}

vector<int> const_min_vec(int n,vector <int> ops){
  vector<int> z;
  while(n>0){
    z.push_back(n);
    if (n%2!=0 && n%3!=0)
    n=n-1;
    else if (n%2==0 && n%3==0)
      n/=3;
    else if (n%2==0){
      if(ops[n-1]<ops[n/2])
      n=n-1;
      else
      n/=2;
    }
    else if (n%3==0)
    {
      if(ops[n-1]<ops[n/3])
      n=n-1;
      else
      n=n/3;
    }
  }
  reverse(z.begin(), z.end());
  return z;
}


vector<int> optimal_sequence(int n) {
  if (n==1)
  return {1};
  vector<int> z,m;
  m=min_ops(n);
  z=const_min_vec(n,m);
  return z;
}




int main() {
  int n;
  cin >> n;
  vector<int> sequence = optimal_sequence(n);
  cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    cout << sequence[i] << " ";
  }
}
