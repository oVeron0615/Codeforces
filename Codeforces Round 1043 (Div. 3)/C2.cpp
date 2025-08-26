#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    ll n, k; cin >> n >> k;

    vector<ll> wm, cost;
    wm.push_back(1), cost.push_back(3);

    ll val = 3, idx = 1;
    while(val <= n)
    {
        wm.push_back(val);
        cost.push_back(val * 3 + idx * (val / 3));
        val *= 3; idx++;
    }
    
    
    ll ans = n * cost[0];
    ll deal = n;
    if(n <= k)
    {
        cout << ans << "\n";
        return;
    }

    idx = 1;
    while(idx < wm.size())
    {
        ll cnt = n/wm[idx];
        if(deal - 2 * cnt > k)
        {
            deal -= 2 * cnt;
            ans += wm[idx-1] * cnt;
        }
        else
        {
            cnt = (deal - k) / 2 + ((deal - k) % 2 ? 1 : 0);
            ans += wm[idx-1] * cnt;
            cout << ans << "\n";
            return;
        }

        idx++;
    }
    cout << -1 << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}