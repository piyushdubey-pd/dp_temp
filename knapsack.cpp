#include <vector>
#include <iostream>
#include <cmath>
using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  
  vector<vector<int>> K(w.size()+1, vector<int>(W+1));
  for (size_t i = 0; i <= w.size(); ++i) {
    for (int j=0;j<=W;j++){
    if (i == 0 || j == 0)
				K[i][j] = 0;
			else if (w[i - 1] <= j)
				K[i][j] = std::max(w[i - 1] + K[i - 1][j - w[i - 1]], K[i - 1][j]);
			else
				K[i][j] = K[i - 1][j];
    }
  }
  return K[w.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
