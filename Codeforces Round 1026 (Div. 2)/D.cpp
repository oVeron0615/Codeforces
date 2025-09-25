#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, m; cin >> n >> m;

    vector<int> b(n+1);
    for(int i=1; i<=n; i++) cin >> b[i];

    vector<vector<pii>> graph(n+1);
    while(m--)
    {
        int s, t, w; cin >> s >> t >> w;
        graph[s].push_back({w, t});
    }

    auto DP = [&](int m)
    {
        vector<int> dp(n+1, -1);
        dp[1] = 0;
        for(int u=1; u<=n; u++)
        {
            if(dp[u] == -1) continue;

            dp[u] = min(dp[u] + b[u], m);
            for(auto [d, v] : graph[u])
            {
                if(dp[u] < d) continue;
                dp[v] = max(dp[v], dp[u]);
            }
        }

        return dp[n] != -1;
    };

    int l = 1, r = 1e9;
    int ans = -1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(DP(m)) ans = m, r = m - 1;
        else l = m + 1;
    }
    cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}