// To force the given implementation of the quick sort algorithm to efficiently process sequences with
// few unique elements, your goal is replace a 2-way partition with a 3-way partition. That is, your new
// partition procedure should partition the array into three parts: < 𝑥 part, = 𝑥 part, and > 𝑥 part.
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& a, int left, int right) {
  int i = left, j = right;
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
  return i;
}

void quick2_sort(vector<int>& a, int left, int right) {
  if (left >= right) return;
  int index = partition(a, left, right);
  if (left < index - 1) quick2_sort(a, left, index - 1);
  if (index < right) quick2_sort(a, index, right);
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  quick2_sort(a, 0, n - 1);
  for (int i = 0; i < n; ++i)
    cout << a[i] << ' ';
  cout << endl;

  return 0;
}
