#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

void solve() {
  int n, kmax;
  cin >> n >> kmax;
  string s, t;
  cin >> s >> t;

  vector<int> step(n);
  int k = 0;
  int idx_s = n - 1;
  for (int idx_t = n - 1; idx_t >= 0; idx_t--) {
    if (idx_s > idx_t) idx_s = idx_t;

    while (idx_s >= 0 && idx_t - idx_s <= kmax) {
      if (t[idx_t] == s[idx_s])
        break;
      else
        idx_s--;
    }

    if (idx_s < 0 || idx_t - idx_s > kmax) {
      cout << -1 << "\n";
      return;
    }

    step[idx_t] = idx_t - idx_s;
    k = max(k, idx_t - idx_s);
  }

  cout << k << "\n";
  while (k--) {
    for (int i = n - 1; i >= 0; i--) {
      if (step[i]) {
        s[i] = s[i - 1];
        step[i]--;
      }
    }
    cout << s << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) solve();
}