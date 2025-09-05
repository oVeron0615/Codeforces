#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 500'001;
int p[MAXN];

void solve()
{
    ll n; cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i];

    ll ans = n * (n + 1) * (n + 2) / 6;
    for(ll i=1; i<n; i++)
        if(p[i] < p[i+1]) ans -= i * (n - i);
    cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}