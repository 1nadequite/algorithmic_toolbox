// decomposition algorithm (Preparata, 1975)

// Given 𝑛 points on a plane, find the smallest distance between a pair of two (different) points. Recall
// that the distance between points (𝑥1, 𝑦1) and (𝑥2, 𝑦2) is equal to √︀(𝑥1 − 𝑥2)^2 + (𝑦1 − 𝑦2)^2
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;
int ax, ay, bx, by;

bool compare_x(const pii& a, const pii& b) {
  return a.first < b.first || (a.first == b.first && a.second < b.second);
}

bool compare_y(const pii& a, const pii& b) {
  return a.second < b.second;
}

void update_min_dist(const pii& a, const pii& b, double& min_dist) {
  double dist = sqrt((a.first - b.first) * (a.first - b.first) * 1.0 + (a.second - b.second) * (a.second - b.second));
  if (dist < min_dist) {
    min_dist = dist;
    ax = a.first; ay = a.second;
    bx = b.first; by = b.second;
  }
}

void rec(vector<pii>& a, int l, int r, double& min_dist) {
  if (r - l <= 3) {
    for (int i = l; i <= r; ++i)
      for (int j = i + 1; j <= r; ++j)
        update_min_dist(a[i], a[j], min_dist);
    sort(a.begin() + l, a.begin() + r + 1, &compare_y); // sort A by y
    return;
  }
  int n = a.size();
  int m = (l + r) >> 1;
  int midx = a[m].first;
  rec(a, l, m, min_dist);
  rec(a, m + 1, r, min_dist);
  vector<pii> t(n);
  merge(a.begin() + l, a.begin() + m + 1, a.begin() + m + 1, a.begin() + r + 1, t.begin(), &compare_y); // merge left and right side A in T, sort of y
  copy(t.begin(), t.begin() + r - l + 1, a.begin() + l);

  int tsz = 0;
  for (int i = l; i <= r; ++i) {
    if (abs(a[i].first - midx) < min_dist) { // find all points with distance from mid less than min_dist
      for (int j = tsz - 1; j >= 0 && (a[i].second - t[j].second < min_dist); --j)
        update_min_dist(a[i], t[j], min_dist);
      tsz++;
    }
  }
}

int main() {
  int n; cin >> n;
  vector<pii> a(n);
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    a[i] = {x, y};
  }
  sort(a.begin(), a.end(), &compare_x); // sort A by x
  double min_dist = 1e18;
  rec(a, 0, n - 1, min_dist);

  cout << "Point 1: " << ax << ' ' << ay << endl;
  cout << "Point 2: " << bx << ' ' << by << endl;
  cout << printf("%.6f", min_dist) << endl;

  return 0;
}
