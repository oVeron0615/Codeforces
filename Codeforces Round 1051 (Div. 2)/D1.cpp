#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];

    const ll MOD = 1e9 + 7;
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(n+1, vector<ll>(n+1, 0)));
    dp[0][0][0] = 1;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            for(int k=0; k<=j; k++)
            {
                dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k]) % MOD;
                if(a[i] >= j) dp[i][a[i]][k] = (dp[i][a[i]][k] + dp[i-1][j][k]) % MOD;
                else if(j > a[i] && a[i] >= k) dp[i][j][a[i]] = (dp[i][j][a[i]] + dp[i-1][j][k]) % MOD;
            }
        }
    }

    int ans = 0;
    for(int j=0; j<=n; j++)
    {
        for(int k=0; k<=n; k++)
        {
            ans = (ans + dp[n][j][k]) % MOD;
        }
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