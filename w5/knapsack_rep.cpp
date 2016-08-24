// knapsack with repetitions: O(n*W)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void knapsack(int W, const vector<int>& w, const vector<int>& v, int n) {
  vector<int> value(W + 1);
  for (int weight = 1; weight <= W; ++weight) {
    for (int i = 0; i < n; ++i) {
      if (w[i] <= weight) {
        value[weight] = max(value[weight], value[weight - w[i]] + v[i]);
      }
    }
  }
  for (auto x: value)
    cout << x << ' ';
  cout << endl;
  cout << value[W] << endl;
}

int main() {
  int n, W; cin >> n >> W;
  vector<int> w(n), v(n);
  for (int i = 0; i < n; ++i) cin >> w[i];
  for (int i = 0; i < n; ++i) cin >> v[i];

  knapsack(W, w, v, n);

  return 0;
}
