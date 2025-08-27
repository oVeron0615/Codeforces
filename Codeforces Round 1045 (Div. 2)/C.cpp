#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n; cin >> n;
    vector<ll> a(n+2, 0);
    for(int i=1; i<=n; i++) cin >> a[i];

    ll ans = 0;
    for(int i=2; i<=n; i+=2)
    {
        if(a[i] < a[i-1] + a[i+1])
        {
            ll sub = a[i-1] + a[i+1] - a[i];
            ans += sub;
            a[i+1] -= min(a[i+1], sub);
        }
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