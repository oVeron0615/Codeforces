#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;

    ll ans = 0;
    vector<ll> upper(n+1), lower(n+1);
    for(ll i=1; i<=n; i++)
    {
        if(s[i] == '1') upper[i] = lower[i-1] + 1;
        else
        {
            upper[i] = upper[i-1] + (i-1);
            lower[i] = lower[i-1] + (n-i);
        }

        ans = max({ans, upper[i], lower[i]});
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