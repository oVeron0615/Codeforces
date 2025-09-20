#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> factor(int val)
{
    vector<int> res;
    for(int i=1; i*i<=val; i++)
    {
        if(val % i == 0) 
        {
            res.push_back(i);
            if(i * i != val) res.push_back(val / i);
        }
    }
    return res;
}

void solve()
{
    int n; cin >> n;
    vector<int> cnt_factor(n+1, 0);

    int ans = 0;
    int g = 0, prev_g;
    for(int i=1; i<=n; i++)
    {
        int ai; cin >> ai;

        prev_g = g;
        g = (i == 1 ? ai : gcd(prev_g, ai));

        vector<int> prev_g_factor = factor(prev_g);
        vector<int> ai_factor = factor(ai);

        for(int x : prev_g_factor)
        {
            if(g % x) ans = max(ans, cnt_factor[x]);
        }
        for(int x : ai_factor)
        {
            cnt_factor[x]++;
            if(g % x) ans = max(ans, cnt_factor[x]);
        }

        cout << ans << " ";
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