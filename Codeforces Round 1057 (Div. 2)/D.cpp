#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 1e18;

ll cost(ll a1, ll a2) { return abs(a1 - a2); }
ll cost(ll a1, ll a2, ll a3) { return max({a1, a2, a3}) - min({a1, a2, a3}); }

void solve()
{
    int n; cin >> n;
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];

    ll ans = INF;

    int t = 4;
    while(t--)
    {
        vector<ll> dp(n+1, INF);
        dp[0] = 0;

        for(int i=2; i<=n; i++)
        {
            dp[i] = min(dp[i], dp[i-2] + cost(a[i], a[i-1]));
            if(i >= 3) dp[i] = min(dp[i], dp[i-3] + cost(a[i], a[i-1], a[i-2]));
        }
        ans = min(ans, dp[n]);

        for(int i=2; i<=n; i++) swap(a[i], a[i-1]);
    }
    cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}

//같은 숫자가 될 구간의 크기를 2, 3으로 나눠 dp를 돌린다.
//크기가 3보다 큰 구간은 구간이 2, 3인 구간으로 나눌 수 있으므로 제외한다.
//환형 dp이므로 최대 구간 크기인 3에 맞춰 구간을 4번 shift해 dp를 돌린다.