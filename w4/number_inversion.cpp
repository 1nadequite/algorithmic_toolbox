// The goal in this problem is to count the number of inversions of a given sequence.
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& a, int begin, int mid, int end, int& num) {
  vector<int> res;
  int j = mid;
  for (int i = begin; i != mid; ++i) {
    for (; j != end && a[j] < a[i]; ++j) {
      res.push_back(a[j]);
      num++;
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
void merge_sort(vector<int>& a, int begin, int end, int& num) {
  if ((begin + 1) == end) return;

  int mid = begin + (end - begin) / 2;
  merge_sort(a, begin, mid, num);
  merge_sort(a, mid, end, num);

  merge(a, begin, mid, end, num);
}

int main() {
  int n, num = 0; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  merge_sort(a, 0, n, num);
  cout << num << endl;

  return 0;
}
