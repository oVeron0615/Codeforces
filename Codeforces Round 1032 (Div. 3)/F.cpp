#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    ll n, s, x; cin >> n >> s >> x;
    vector<ll> a(n+1), sum(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) sum[i] = sum[i-1] + a[i];

    ll ans = 0;
    map<ll, ll> sum_cnt;

    int l = 0;
    for(int i=1; i<=n; i++)
    {
        if(a[i] == x)
        {
            for(int j=l; j<i; j++) sum_cnt[sum[j]]++;
            l = i;
        }
        else if(a[i] > x)
        {
            sum_cnt.clear();
            l = i;
        }

        ans += sum_cnt[sum[i]-s];
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