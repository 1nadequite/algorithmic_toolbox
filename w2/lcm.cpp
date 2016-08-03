// least commot multiple
#include <iostream>

using namespace std;
typedef long long ll;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

ll lcm(int a, int b) {
  return a / gcd(a, b) * b;
}

int main() {
  int a, b; cin >> a >> b;
  cout << lcm(a, b) << endl;

  return 0;
}
