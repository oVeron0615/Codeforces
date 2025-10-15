#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    ll n, m, k; cin >> n >> m >> k;
    ll val = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cout << (val++ + (m % k ? 0 : i)) % k + 1 << " ";
        }
        cout << "\n";
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}

//k가 m으로 나누어 떨어지면 shift하고, 나누어 떨어지면 하지 않는다.