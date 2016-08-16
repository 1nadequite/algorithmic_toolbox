// The goal in this code problem is to check whether an input sequence contains a majority element.
#include <iostream>
#include <vector>

using namespace std;

// merge sort with extra memory
vector<int> merge(const vector<int>& left, const vector<int>& right) {
  vector<int> res;
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

vector<int> merge_sort(const vector<int>& a) {
  int n = a.size();
  if (n == 1) return a;
  int m = n / 2;
  vector<int> left_side = {a.begin(), a.begin() + m};
  vector<int> right_side = {a.begin() + m, a.end()};
  vector<int> left = merge_sort(left_side);
  vector<int> right = merge_sort(right_side);
  return merge(left, right);
}

int majority_element(const vector<int>& a, int n) {
  int count = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i - 1]) count++;
    else {
      if (count > n / 2) return 1;
      count = 1;
    }
  }
  if (count > n / 2) return 1;
  else return 0;
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  cout << majority_element(merge_sort(a), n) << endl;

  return 0;
}
