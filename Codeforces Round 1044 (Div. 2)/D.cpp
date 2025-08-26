#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 200'001;
int n;
ll h[MAXN], dp[MAXN];

void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++) cin >> h[i];

    dp[0] = 0, dp[1] = h[1];
    for(int i=2; i<=n; i++)
        dp[i] = min(dp[i-1] + h[i] - 1, dp[i-2] + h[i-1] + max(0LL, h[i] - (i - 1)));
    cout << dp[n] << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}