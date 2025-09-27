#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    ll n, y; cin >> n >> y;
    vector<ll> c(n+1);
    for(ll i=1; i<=n; i++) cin >> c[i];

    const ll sz = 2e5;
    vector<ll> cnt_c(sz+1);
    for(ll i=1; i<=n; i++) cnt_c[c[i]]++;

    vector<ll> psum(sz+1);
    for(ll i=1; i<=sz; i++) psum[i] = psum[i-1] + cnt_c[i];

    ll ans = LLONG_MIN;
    for(ll x=2; x<=sz; x++)
    {
        ll sum = 0;
        for(ll new_price = 1; new_price <= (sz + x - 1) / x; new_price++)
        {
            ll cnt_new_price = psum[min(new_price * x, sz)] - psum[(new_price - 1) * x];
            sum += cnt_new_price * new_price;
            sum -= y * (max(cnt_new_price - cnt_c[new_price], 0LL));
        }
        ans = max(ans, sum);
    }
    cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}