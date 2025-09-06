#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 998244353;
const int SZ = 200'001;

struct seg
{
    ll l, p, q;
};

ll sq(ll n, ll val)
{
    if(n == 0) return 1;

    ll res = sq(n/2, val);
    res = res * res % MOD;
    if(n % 2) res = res * val % MOD;
    return res;
}

void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<seg>> r_seg(m+1);
    vector<ll> dp(m+1, 0);
    ll den = 1;

    dp[0] = 1;
    for(int i=1; i<=n; i++)
    {
        ll l, r, p, q; cin >> l >> r >> p >> q;
        r_seg[r].push_back({l, p, q});
        dp[0] = dp[0] * (q - p) % MOD;
        den = den * q % MOD;
    }

    for(int r=1; r<=m; r++)
    {
        for(auto [l, p, q] : r_seg[r])
        {
            dp[r] = (dp[r] + dp[l-1] * p % MOD * sq(MOD-2, q - p) % MOD) % MOD;
        }
    }

    cout << dp[m] * sq(MOD-2, den) % MOD << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    solve();
}