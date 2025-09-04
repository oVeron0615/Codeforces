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
        score[i] = i;
        for(int j=1; j<i; j++)
            score[i] = score[i] * score[j] % MOD;
    }

    ll ans = 1;
    for(int i=1; i<=n; i++)
    {
        if(s[i] <= 31 && k >= (1 << (s[i] - 1)))
        {
            k -= (1 << (s[i] - 1));
            ans = ans * score[s[i]] % MOD;
        }
        else
        {
            ll last = s[i];
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
            break;
        }
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