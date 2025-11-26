#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

void solve() {
  int n;
  cin >> n;
  vector<int> p(n + 1);
  for (int i = 1; i <= n; i++) cin >> p[i];
  string bs;
  cin >> bs;
  bs = "#" + bs;

  int pos_1, pos_n;
  for (int i = 1; i <= n; i++) {
    if (p[i] == 1)
      pos_1 = i;
    else if (p[i] == n)
      pos_n = i;
  }

  if (bs[pos_1] == '1' || bs[pos_n] == '1' || bs[1] == '1' || bs[n] == '1')
    cout << -1 << "\n";
  else {
    cout << 5 << "\n";
    cout << 1 << " " << pos_1 << "\n";
    cout << 1 << " " << pos_n << "\n";
    cout << pos_1 << " " << n << "\n";
    cout << pos_n << " " << n << "\n";
    cout << min(pos_1, pos_n) << " " << max(pos_1, pos_n) << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) solve();
}