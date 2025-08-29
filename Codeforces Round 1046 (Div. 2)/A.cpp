#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int a, b, c, d; cin >> a >> b >> c >> d;
    c -= a, d -= b;
    
    if(max(a, b) <= 2 * min(a, b) + 2 && max(c, d) <= 2 * min(c, d) + 2)
        cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}