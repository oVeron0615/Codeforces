#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    const ll MOD = 998'244'353;

    int n; cin >> n;
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];

    vector<ll> inv(n + 1);
    inv[1] = 1;
    for(ll i=2; i<=n; i++) inv[i] = (MOD - MOD / i * inv[MOD % i] % MOD) % MOD;

    ll ans = 1;
    ll num = 0;
    for(int i=n; i>=1; i--)
    {
        if(i * 2 == n + 1) num += 1;
        else if(i <= (n + 1) / 2) num += 2;

        ll den = a[i];
        if(num < den)
        {
            cout << 0 << "\n";
            return;
        }

        for(ll i=1; i<=den; i++) ans = ans * (num - i + 1) % MOD * inv[i] % MOD;
        num -= den;
    }
    cout << (num ? 0 : ans) << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}