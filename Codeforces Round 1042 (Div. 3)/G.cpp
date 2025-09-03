#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MAXN = 200'001, MOD = 1e9 + 7;
ll n, k;
ll s[MAXN];
ll score[32];

void solve()
{
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> s[i];
    sort(s + 1, s + n + 1);

    for(int i=1; i<=31; i++)
    {
        ll f = 1;
        for(int j=1; j<i; j++)
            f = f * score[j] % MOD;
        score[i] = (score[i-1] * score[i-1] % MOD + f) % MOD;
    }

    ll ans = 1;
    int idx = 1;
    while(idx <= n && s[idx] <= 31)
    {
        if(k >= (1 << (s[idx] - 1)))
        {
            k -= (1 << (s[idx] - 1));
            ans = ans * score[s[idx]] % MOD;
        }
        else break;
        idx++;
    }

    ll last = s[idx];
    while(k)
    {
        k--;
        ans = ans * last % MOD;

        ll num = 1;
        while(k >= (1 << (num - 1)))
        {
            k -= (1 << (num - 1));
            ans = ans * score[num] % MOD;
            num++;
        }

        last = num;
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