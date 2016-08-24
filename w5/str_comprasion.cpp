// alignment string
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int maxn = 1005;
int dp[maxn][maxn];
string s, t;

int editDistance(string& s, string& t) {
  int n = s.size();
  int m = t.size();
  for (int i = 0; i <= n; ++i) dp[i][0] = i;
  for (int i = 0; i <= m; ++i) dp[0][i] = i;

  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n; ++i) {
      int insertion = dp[i][j - 1] + 1;
      int deletion = dp[i - 1][j] + 1;
      int match = dp[i - 1][j - 1];
      int mismatch = dp[i - 1][j - 1] + 1;
      if (s[i - 1] == t[j - 1]) dp[i][j] = min( min(insertion, deletion), match );
      else dp[i][j] = min( min(insertion, deletion), mismatch );
    }
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      cout << dp[i][j] << ' ' ;
    }
    cout << endl;
  }
  return dp[n][m];
}

void outputAlignment(int i, int j) {
  if (i == 0 && j == 0) return;
  else {
    if (i > 0 && dp[i][j] == dp[i - 1][j] + 1) {
      outputAlignment(i - 1, j);
      cout << s[i - 1] << " | -" << endl;
    }
    else if (j > 0 && dp[i][j] == dp[i][j - 1] + 1) {
      outputAlignment(i, j - 1);
      cout << "- | " << t[j - 1] << endl;
    }
    else {
      outputAlignment(i - 1, j - 1);
      cout << s[i - 1] << " | " << t[j - 1] << endl;
    }
  }
}

int main() {
  cin >> s >> t;

  cout << editDistance(s, t) << endl;
  outputAlignment(s.size(), t.size());

  return 0;
}
