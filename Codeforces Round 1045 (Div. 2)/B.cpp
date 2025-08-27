#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    ll n, k; cin >> n >> k;
    for(int i=1; i<=n; i++)
    {
        ll ai; cin >> ai;
        cout << ai + (ai % (k + 1)) * k << " ";
    }
    cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}