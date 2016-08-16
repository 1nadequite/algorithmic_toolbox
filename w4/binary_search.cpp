// The goal in this code problem is to implement the binary search algorithm.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(const vector<int>& a, int x) {
  int l = 0, r = a.size() - 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (x < a[mid]) r = mid;
    else l = mid;
  }
  if (a[l] == x) return l;
  else if (a[r] == x) return r;
  else return -1;
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  int m; cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) cin >> b[i];

  for (int i = 0; i < m; ++i)
    cout << binary_search(a, b[i]) << ' ';
  cout << endl;

  return 0;
}
