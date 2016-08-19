// You are given a set of points on a line and a set of segments on a line. The goal is to compute, for
// each point, the number of segments that contain this point.
#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef pair<int, int> pii;

// merge sort for vector<int, int>
vector<pii> merge(const vector<pii>& left, const vector<pii>& right) {
  vector<pii> res;
  int i = 0, j = 0;
  while (i < left.size() && j < right.size()) {
    if (left[i] < right[j]) {
      res.push_back(left[i]);
      i++;
    } else {
      res.push_back(right[j]);
      j++;
    }
  }
  while (i < left.size()) {
    res.push_back(left[i]);
    i++;
  }
  while (j < right.size()) {
    res.push_back(right[j]);
    j++;
  }
  return res;
}

vector<pii> merge_sort(const vector<pii>& a) {
  int n = a.size();
  if (n == 1) return a;
  int m = n / 2;
  vector<pii> left_side = {a.begin(), a.begin() + m};
  vector<pii> right_side = {a.begin() + m, a.end()};
  vector<pii> left = merge_sort(left_side);
  vector<pii> right = merge_sort(right_side);
  return merge(left, right);
}

int main() {
  int n, m; cin >> n >> m;
  vector<pii> a;
  map<int, int> pos;
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    a.push_back({x, 0});
    a.push_back({y, 2});
  }
  for (int i = 0; i < m; ++i) {
    int x; cin >> x;
    a.push_back({x, 1});
    pos[x] = i;
  }

  vector<pii> sort_a;
  sort_a = merge_sort(a);

  vector<int> ans(m);
  int cnt = 0;
  for (auto x: sort_a) {
    if (x.second == 0) cnt++;
    else if (x.second == 2) cnt--;
    else ans[pos[x.first]] = cnt;
  }
  for (auto x: ans)
    cout << x << ' ';
  cout << endl;

  return 0;
}
