#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    multiset<int> s, t;

    int n, k; cin >> n >> k;
    for(int i=1; i<=n; i++)
    {
        int Si; cin >> Si;
        Si %= k;
        s.insert(min(Si, k - Si));
    }
    for(int i=1; i<=n; i++)
    {
        int Ti; cin >> Ti;
        Ti %= k;
        t.insert(min(Ti, k - Ti));
    }

    if(s == t) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}