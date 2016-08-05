// Given a set of 𝑛 segments {[𝑎0, 𝑏0], [𝑎1, 𝑏1], . . . , [𝑎𝑛−1, 𝑏𝑛−1]} with integer coordinates on a line, find
// the minimum number 𝑚 of points such that each segment contains at least one point. That is, find a
// set of integers 𝑋 of the minimum size such that for any segment [𝑎𝑖
// , 𝑏𝑖
// ] there is a point 𝑥 ∈ 𝑋 such
// that 𝑎𝑖 ≤ 𝑥 ≤ 𝑏𝑖
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n; cin >> n;
  vector<int> a(n), b(n), used(n), ans;
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

  for (int i = 0; i < n; ++i) {
    if (used[i]) continue;
    used[i] = true;
    int l = a[i], r = b[i];
    for (int j = i + 1; j < n; ++j) {
      if (a[i] > b[j] || a[j] > b[i] || used[j]) continue;
      l = max(l, a[j]);
      r = min(r, b[j]);
      if (l <= r) used[j] = true;
    }
    if (l <= r) ans.push_back(r);
  }
  cout << ans.size() << endl;
  for (auto& x: ans)
    cout << x << ' ';
  cout << endl;

  return 0;
}
