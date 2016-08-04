// Given two non-negative integers 𝑚 and 𝑛, where 𝑚 ≤ 𝑛, find the last digit of the sum 𝐹𝑚 + 𝐹𝑚+1 +
// · · · + 𝐹𝑛.
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int mod = 10000;

int fibo(ll n) {
  n += 2;
  int a = 1, b = 1, c = 1, d = 0;
  int ta, tb, tc;
  int rc = 0, rd = 1;

  while (n) {
    if (n % 2 == 1) {
      tc = rc;
      rc = (tc * a + rd * c) % mod;
      rd = (tc * b + rd * d) % mod;
    }

    ta = a, tb = b, tc = c;
    a = (ta * ta + tb * tc) % mod;
    b = (ta * tb + tb * d) % mod;
    c = (ta * tc + tc * d) % mod;
    d = (tb * tc + d * d) % mod;

    n >>= 1;
  }
  return (rc - 1);
}

int partsum_fibo(ll m, ll n) {
  return (fibo(n) - fibo(m - 1)) % 10;
}

int main() {
  ll n, m; cin >> m >> n;
  cout << partsum_fibo(m, n) << endl;

  return 0;
}
