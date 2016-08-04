// Given two sequences 𝑎1, 𝑎2, . . . , 𝑎𝑛 (𝑎𝑖
// is the profit per click of the 𝑖-th ad) and 𝑏1, 𝑏2, . . . , 𝑏𝑛 (𝑏𝑖
// is
// the average number of clicks per day of the 𝑖-th slot), we need to partition them into 𝑛 pairs (𝑎𝑖
// , 𝑏𝑗 )
// such that the sum of their products is maximized.
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n; cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int sum = 0;
  for (int i = 0; i < n; ++i)
    sum += a[i] * b[i];
  cout << sum << endl;

  return 0;
}
