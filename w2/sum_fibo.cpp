// Given an integer 𝑛, find the last digit of the sum 𝐹0 + 𝐹1 + · · · + 𝐹𝑛.
// sum(𝐹0 + 𝐹1 + · · · + 𝐹𝑛) = 𝐹(𝑛+2) - 1
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
  return (rc - 1) % 10;
}

int main() {
  ll n; cin >> n;
  cout << fibo(n) << endl;

  return 0;
}
