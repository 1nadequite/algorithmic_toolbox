#include <iostream>
#include <vector>

using namespace std;
const int inf = 1e9;

int DPchange(int money, const vector<int>& a) {
  vector<int> min_coin(money);
  min_coin[0] = 0;
  for (int m = 1; m <= money; ++m) {
    min_coin[m] = inf;
    for (auto i: a) {
      if (m >= i) {
        int num_coins = min_coin[m - i] + 1;
        if (num_coins < min_coin[m])
          min_coin[m] = num_coins;
      }
    }
  }
  return min_coin[money - 1];
}

int main() {
  int money, n; cin >> money >> n;
  vector<int> coin(n);
  for (int i = 0; i < n; ++i) cin >> coin[i];

  cout << DPchange(money, coin) << endl;

  return 0;
}
