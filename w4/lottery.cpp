// You are given a set of points on a line and a set of segments on a line. The goal is to compute, for
// each point, the number of segments that contain this point.
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<pair<int, int>>& a, int left, int right) {
  int i = left, j = right;
  int pivot = a[left + (right - left) / 2].first;

  while (i <= j) {
    while (a[i].first < pivot) i++;
    while (a[j].first > pivot) j--;
    if (i <= j) {
      swap(a[i], a[j]);
      i++;
      j--;
    }
  }
  return i;
}

void quick2_sort(vector<pair<int, int>>& a, int left, int right) {
  if (left >= right) return;
  int index = partition(a, left, right);
  if (left < index - 1) quick2_sort(a, left, index - 1);
  if (index < right) quick2_sort(a, index, right);
}

int binary_search(const vector<pair<int, int>>& a, int x) {
  int l = 0, r = a.size() - 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (x < a[mid].first) r = mid;
    else l = mid;
  }
  int ans = 0;
  if (a[l].first <= x && x <= a[l].second) ans++;
  else if (a[r].first <= x && x <= a[r].second) ans++;
  return ans;
}

int main() {
  int n, m; cin >> n >> m;
  vector<pair<int, int>> a(n);
  vector<int> b(m);
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    a[i] = {x, y};
  }
  for (int i = 0; i < m; ++i) cin >> b[i];

  vector<int> res(m);
  quick2_sort(a, 0, n - 1);
  /*for (int i = 0; i < m; ++i)
    res[i] += binary_search(a, b[i]);
  for (auto x: res)
    cout << x << ' ';
  cout << endl;*/
  for (auto x: a)
    cout << x.first << ' ' << x.second << endl;

  return 0;
}
