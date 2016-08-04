// Compose the largest number out of a set of integers.
#include <iostream>
#include <vector>

using namespace std;
vector<int> digits;

void largest_number(vector<int> const& a) {
  for (int i = 0; i < a.size(); ++i) {
    int n = a[i];
    while (n) {
      if (n == 0) return;
      digits.push_back(n % 10);
      n /= 10;
    }
  }
  sort(digits.begin(), digits.end());
  reverse(digits.begin(), digits.end());
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  largest_number(a);
  for (auto x: digits)
    cout << x;
  cout << endl;

  return 0;
}
