#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    ll n; cin >> n;
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];

    ll ans = 0;
    for(int i=1; i<=n; i++)
    {
        if(i % 2) ans += a[i];
        else ans -= a[i];
    }

    ll max_swap_val = 0;
    ll min_odd = LLONG_MAX / 2, min_even = LLONG_MAX / 2;
    for(int i=1; i<=n; i++)
    {
        if(i % 2) 
        {
            max_swap_val = max(max_swap_val, i - 2 * a[i] - min_even);
            min_odd = min(min_odd, i + 2 * a[i]);
        }
        else
        {
            max_swap_val = max(max_swap_val, i + 2 * a[i] - min_odd);
            min_even = min(min_even, i - 2 * a[i]);
        } 
    }

    cout << ans + max(max_swap_val, n % 2 ? n - 1 : n - 2) << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}