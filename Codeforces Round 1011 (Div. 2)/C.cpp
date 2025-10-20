#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    ll x, y; cin >> x >> y;
    cout << (x == y ? -1 : (1LL << 48) - max(x, y)) << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}

/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    ll x, y; cin >> x >> y;

    ll ans = 0;
    for(int i=0; i<63; i++)
    {
        if(x & (1LL << i) && y & (1LL << i))
        {
            int k = i - 1;
            while(k >= 0)
            {
                if((x ^ y) & (1LL << k)) break;
                k--;
            }
            
            ll plus = (1LL << i) - (k == -1 ? 0 : (1LL << k));
            x += plus;
            y += plus;
            ans += plus;
        }
    }

    cout << (ans <= 1e18 ? ans : -1) << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}
*/