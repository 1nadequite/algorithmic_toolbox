#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> poly_mult(const vector<int>& a, const vector<int>& b, int n, int al, int bl) {
  vector<int> res(2 * n - 1);
  if (n == 1) {
    res[0] = a[al] * b[bl];
    return res;
  }
  vector<int> res_left = poly_mult(a, b, n / 2, al, bl);
  vector<int> res_right = poly_mult(a, b, n / 2, al + n / 2, bl + n / 2);
  for (int i = 0; i < n - 1; ++i) {
    res[i] = res_left[i];
    res[i + n] = res_right[i];
  }
  vector<int> d1e0 = poly_mult(a, b, n / 2, al, bl + n / 2);
  vector<int> d0e1 = poly_mult(a, b, n / 2, al + n / 2, bl);
  for (int i = 0; i < n - 1; ++i)
    res[i + n / 2] += d1e0[i] + d0e1[i];
  return res;
}

int main() {
  int n = 4;
  vector<int> a = {4, 3, 2, 1};
  vector<int> b = {1, 2, 3, 4};

  vector<int> res = poly_mult(a, b, n, 0, 0);
  for (int i = res.size() - 1; i >= 0; --i) {
    if (i == 0) cout << res[i] << ' ';
    else if (i == 1) cout << res[i] << "x" << " + ";
    else cout << res[i] << "x^" << i << " + ";
  }
  cout << endl;

  return 0;
}
