// The goal of this code problem is to implement an algorithm for the fractional knapsack problem.
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n, W; cin >> n >> W;
  double V = 0;
  vector<pair<double, pair<int, int>>> a(n);
  for (int i = 0; i < n; ++i) {
    int v, w; cin >> v >> w;
    a[i] = {(v * 1.0 / w), {v, w}};
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    if (W == 0) break;
    if (W > a[i].second.second) {
      W -= a[i].second.second;
      V += a[i].second.first;
    } else {
      V += W * a[i].first;
      W = 0;
    }
  }
  printf("%.4f\n", V);

  return 0;
}
