#include <iostream>
#include <vector>

using namespace std;

void partition(vector<int>& a, int left, int right, int& i, int& j) {
  i = left, j = right;
  int pivot = a[left + (right - left) / 2];

  while (i <= j) {
    while (a[i] < pivot) i++;
    while (a[j] > pivot) j--;
    if (i <= j) {
      swap(a[i], a[j]);
      i++;
      j--;
    }
  }
}

void quick3_sort(vector<int>& a, int left, int right) {
  if (left >= right) return;
  int i, j;
  partition(a, left, right, i, j);
  quick3_sort(a, left, j);
  quick3_sort(a, i, right);
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  quick3_sort(a, 0, n - 1);
  for (int i = 0; i < n; ++i)
    cout << a[i] << ' ';
  cout << endl;

  return 0;
}

