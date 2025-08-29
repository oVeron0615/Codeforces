#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n; cin >> n;
    ll C1 = 1e18, C2 = 1e18;
    for(int i=1; i<=n; i++)
    {
        ll x, y; cin >> x >> y;
        C1 = min(C1, -x-y);
        C2 = min(C2, -x+y);
    }

    ll V = 1e9;
    ll D1, D2;
    for(int i=1; i<=2; i++)
    {
        cout << "? U " << V << "\n";
        cout.flush();
        cin >> D1;
        cout << "? R " << V << "\n";
        cout.flush();
        cin >> D1;
    }
    for(int i=1; i<=4; i++)
    {
        cout << "? D " << V << "\n";
        cout.flush();
        cin >> D2;
    }

    cout << "! " << (D1 + D2 - C1 - C2 - 8*V) / 2 << " " << (D1 - D2 - C1 + C2) / 2 << "\n";
    cout.flush();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}