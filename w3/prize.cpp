// The goal of this problem is to represent a given positive integer 𝑛 as a sum of as many pairwise
// distinct positive integers as possible. That is, to find the maximum 𝑘 such that 𝑛 can be written as
// 𝑎1 + 𝑎2 + · · · + 𝑎𝑘 where 𝑎1, . . . , 𝑎𝑘 are positive integers and 𝑎𝑖 ̸= 𝑎𝑗 for all 1 ≤ 𝑖 < 𝑗 ≤ 𝑘.
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n; cin >> n;
  vector<int> a;
  int cur = 1;
  while (n) {
    if ((2 * cur + 1) <= n) {
      a.push_back(cur);
      n -= cur;
      cur++;
    }
    else {
      a.push_back(n);
      n = 0;
    }
  }
  cout << a.size() << endl;
  for (auto& x: a)
    cout << x << ' ';
  cout << endl;

  return 0;
}
