// fibonacci numbers
#include <iostream>
#include <vector>

using namespace std;

long long fibo(int n) {
  vector<long long> f(n);
  f[0] = 0; f[1] = 1;
  for (int i = 2; i <= n; ++i)
    f[i] = f[i - 1] + f[i - 2];
  return f[n];
}

int main() {
  int n; cin >> n;
  cout << fibo(n) << endl;

  return 0;
}
