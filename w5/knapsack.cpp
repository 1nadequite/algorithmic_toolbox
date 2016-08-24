#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxn = 1005;
int dp[maxn][maxn];

void knapsack(int W, const vector<int>& w, const vector<int>& v, int n) {
  for (int i = 0; i <= W; ++i) dp[0][i] = 0;
  for (int i = 0; i <= n; ++i) dp[i][0] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int weight = 1; weight <= W; ++weight) {
      dp[i][weight] = dp[i - 1][weight];
      if (w[i - 1] <= weight) {
        dp[i][weight] = max(dp[i][weight], dp[i - 1][weight - w[i - 1]] + v[i - 1]);
      }
    }
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= W; ++j) {
      cout << dp[i][j] << ' ';
    }
    cout << endl;
  }
  cout << dp[n][W] << endl;
}

int main() {
  int n, W; cin >> n >> W;
  vector<int> w(n), v(w);
  for (int i = 0; i < n; ++i) cin >> w[i];
  for (int i = 0; i < n; ++i) cin >> v[i];

  knapsack(W, w, v, n);

  return 0;
}
