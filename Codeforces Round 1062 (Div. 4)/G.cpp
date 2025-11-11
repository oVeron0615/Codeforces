#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n; cin >> n;
    vector<ll> dp(n, 0), c(n), a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> c[i];

    ll sum = 0;
    for(ll ci : c) sum += ci;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(a[j] <= a[i]) dp[i] = max(dp[i], dp[j]);
        }
        dp[i] += c[i];
    }

    cout << accumulate(c.begin(), c.end(), 0LL) - *max_element(dp.begin(), dp.end()) << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}