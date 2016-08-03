// Given two integers 𝑛 and 𝑚, output 𝐹𝑛 mod 𝑚 (that is, the remainder of 𝐹𝑛 when divided by 𝑚)
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef long double ld;

int fibo(ll n, int mod) {
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
  return rc;
}

int main() {
  ll n; int m; cin >> n >> m;
  cout << fibo(n, m) << endl;

  return 0;
}
