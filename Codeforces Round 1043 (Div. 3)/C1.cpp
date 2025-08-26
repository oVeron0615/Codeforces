#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    ll n; cin >> n;

    vector<ll> wm, cost;
    wm.push_back(1), cost.push_back(3);

    ll val = 3, idx = 1;
    while(val <= n)
    {
        wm.push_back(val);
        cost.push_back(val * 3 + idx * (val / 3));
        val *= 3; idx++;
    }
    
    
    ll ans = 0;
    idx = wm.size()-1;
    while(n)
    {
        ans += (n / wm[idx]) * cost[idx];
        n %= wm[idx];
        idx--;
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