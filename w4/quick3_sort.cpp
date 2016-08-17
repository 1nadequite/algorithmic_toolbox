/* This function partitions a[] in three parts
 * a) a[l..i] contains all elements smaller than pivot
 * b) a[i+1..j-1] contains all occurrences of pivot
 * c) a[j..r] contains all elements greater than pivot */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void partition(vector<int>& a, int left, int right, int &i, int &j) {
  i = left - 1, j = right;
  int p = left - 1, q = right;
  int pivot = a[right];

  while (true) {
    while (a[++i] < pivot);
    while (a[--j] > pivot)
      if (j == left)
        break;

    if (i >= j) break;

    swap(a[i], a[j]);

    if (a[i] == pivot) {
      p++;
      swap(a[p], a[i]);
    }
    if (a[j] == pivot) {
      q--;
      swap(a[q], a[j]);
    }
  }
  swap(a[i], a[right]);
  j = i - 1;
  for (int k = left; k < p; k++, j--)
    swap(a[k], a[j]);
  i = i + 1;
  for (int k = right - 1; k > q; k--, i++)
    swap(a[k], a[i]);
}

void quick3_sort(vector<int>& a, int left, int right) {
  if (left >= right) return;
  int i, j;
  partition(a, left, right, i, j);
  quick3_sort(a, left, j);
  quick3_sort(a, i, right);
}

void print_arr(const vector<int>& a, int n) {
  for (int i = 0; i < n; ++i)
    cout << a[i] << ' ';
  cout << endl;
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  print_arr(a, n);
  quick3_sort(a, 0, n - 1);
  print_arr(a, n);

  return 0;
}

