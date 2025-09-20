#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> depth(n+1);
    vector<bool> is_leaf(n+1, true);

    depth[1] = 1;
    for(int u=2; u<=n; u++)
    {
        int p; cin >> p;
        depth[u] = depth[p] + 1;
        is_leaf[p] = false;
    }

    int mxD = INT_MAX;
    for(int u=1; u<=n; u++)
        if(is_leaf[u]) mxD = min(mxD, depth[u]);

    vector<int> depth_cnt(n+1);
    for(int u=1; u<=n; u++)
        if(depth[u] <= mxD) depth_cnt[depth[u]]++;

    vector<int> dp(k+1);
    dp[0] = 1;
    for(int i=1; i<=mxD; i++)
    {
        for(int j=k; j>=0; j--)
        {
            if(j + depth_cnt[i] <= k)
                dp[j + depth_cnt[i]] |= dp[j];
        }
    }

    int cnt_node = 0;
    for(int i=0; i<=mxD; i++) cnt_node += depth_cnt[i];

    for(int i=0; i<=k; i++)
    {
        if(dp[i])
        {
            if(cnt_node - i <= n - k)
            {
                cout << mxD << "\n";
                return;
            }
        }
    }
    cout << mxD - 1 << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}