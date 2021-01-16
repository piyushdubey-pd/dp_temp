#include <iostream>
#include <bits/stdc++.h>

int get_change(int m) {
  int minnum[m+1];
  
  minnum[0]=0;

  int coins[]={1,3,4};
  
  for(int i=1;i<=m;i++)
    minnum[i]=INT_MAX;
  
  for(int i=1;i<=m;i++){
    for(int j=0;j<3;j++)
    if(coins[j]<=i){
      int t=minnum[i-coins[j]];
      if(t!=INT_MAX  && t+1<minnum[i])
      minnum[i]=t+1;
    }
  }
  return minnum[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
