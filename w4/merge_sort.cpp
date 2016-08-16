#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& a, int begin, int mid,  int end) {
  vector<int> res;
  int j = mid;
  for (int i = begin; i != mid; ++i) {
    for (; j != end && a[j] < a[i]; ++j) {
      res.push_back(a[j]);
    }
    res.push_back(a[i]);
  }
  for (; j != end; ++j)
    res.push_back(a[j]);
  for (auto x: res) {
    a[begin] = x;
    begin++;
  }
}

// merge sort without extra memory
void merge_sort(vector<int>& a, int begin, int end) {
  if ((begin + 1) == end) return;

  int mid = begin + (end - begin) / 2;
  merge_sort(a, begin, mid);
  merge_sort(a, mid, end);

  merge(a, begin, mid, end);
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  merge_sort(a, 0, n);
  for (auto x: a)
    cout << x << ' ';
  cout << endl;

  return 0;
}
