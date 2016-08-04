// The goal in this problem is to find the minimum number of coins needed to change the input value
// (an integer) into coins with denominations 1, 5, and 10.
#include <iostream>

using namespace std;

int main() {
  int m, coins = 0; cin >> m;
  coins += m / 10;
  m %= 10;
  coins += m / 5;
  m %= 5;
  coins += m;
  cout << coins << endl;

  return 0;
}
