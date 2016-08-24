#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
const int inf = 1e9;
const int maxn = 1005;
int m[maxn][maxn], M[maxn][maxn];

int oper(int x, char c, int y) {
  if (c == '+') return x + y;
  else if (c == '-') return x - y;
  else return x * y;
}

void MinAndMax(int i, int j, const vector<int>& d, const vector<char>& op) {
  int mn = inf;
  int mx = -inf;
  for (int k = i; k < j; ++k) {
    int a = oper(M[i][k], op[k], M[k + 1][j]);
    int b = oper(M[i][k], op[k], m[k + 1][j]);
    int c = oper(m[i][k], op[k], M[k + 1][j]);
    int d = oper(m[i][k], op[k], m[k + 1][j]);
    mn = min( mn, min( min(a, b), min(c, d) ) );
    mx = max( mx, max( max(a, b), max(c, d) ) );
  }
  m[i][j] = mn;
  M[i][j] = mx;
}

void parentheses(const vector<int>& d, const vector<char>& op, int n) {
  n = n / 2 + 1;
  for (int i = 0; i < n; ++i) {
    m[i][i] = d[i];
    M[i][i] = d[i];
  }
  for (int s = 1; s < n; ++s) {
    for (int i = 0; i < n - s; ++i) {
      int j = i + s;
      MinAndMax(i, j, d, op);
    }
  }
  cout << "Min: " << m[0][n - 1] << endl;
  cout << "Max: " << M[0][n - 1] << endl;
}

int main() {
  int n; cin >> n;
  vector<int> d;
  vector<char> op;
  for (int i = 0; i < n; ++i) {
    char c; cin >> c;
    if (c == '+' || c == '-' || c == 'x') op.push_back(c);
    else d.push_back(c - '0');
  }

  parentheses(d, op, n);

  return 0;
}
