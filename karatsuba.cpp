#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int n;

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
  auto an = a.size();
  vector<int> res(2 * an - 1);

  if (an == 1) {
    res[0] = a[0] * b[0];
    return res;
  }

  auto k = an / 2;
  vector<int> low1 = {a.begin(), a.begin() + k};
  vector<int> hight1 = {a.begin() + k, a.end()};
  vector<int> low2 = {b.begin(), b.begin() + k};
  vector<int> hight2 = {b.begin() + k, b.end()};

  vector<int> p1 = karatsuba(low1, hight1);
  vector<int> p2 = karatsuba(low2, hight2);

  vector<int> total1(k), total2(k);
  for (int i = 0; i < k; ++i) {
    total1[i] = low1[i] + hight1[i];
    total2[i] = low2[i] + hight2[i];
  }

  vector<int> p3 = karatsuba(total1, total2);

  for (int i = 0; i < an; ++i) p3[i] -= p2[i] + p1[i];
  for (int i = 0; i < an; ++i) res[i] = p2[i];
  for (int i = an; i < 2 * an; ++i) res[i] = p1[i - an];
  for (int i = k; i < an + k; ++i) res[i] += p3[i - k];

  return res;
}

int main() {
  n = 4;
  vector<int> a = {4, 3, 2, 1};
  vector<int> b = {1, 2, 3, 4};

  for (auto x: karatsuba(a, b))
    cout << x << ' ';
  cout << endl;

  return 0;
}
