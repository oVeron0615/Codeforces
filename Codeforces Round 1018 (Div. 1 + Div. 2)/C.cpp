#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;

ll retVal(vector<vector<int>>& grid, vector<ll>& cost)
{
    vector<vector<ll>> dp(n+1, vector<ll>(2, 1e18));
    dp[1][0] = 0, dp[1][1] = cost[1];
    for(int i=2; i<=n; i++)
    {
        for(int x=0; x<2; x++)
        {
            for(int y=0; y<2; y++)
            {
                bool can_hire = true;
                for(int j=1; j<=n; j++)
                    if(grid[i][j] + x == grid[i-1][j] + y) can_hire = false;
                
                if(can_hire)
                {
                    if(x == 0) dp[i][x] = min(dp[i][x], dp[i-1][y]);
                    else dp[i][x] = min(dp[i][x], dp[i-1][y] + cost[i]);
                }
            }
        }
    }
    return min(dp[n][0], dp[n][1]);
}

void solve()
{
    cin >> n;
    vector<vector<int>> grid(n+1, vector<int>(n+1));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> grid[i][j];
    
    vector<ll> a(n+1), b(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];

    ll ans = retVal(grid, a);
    for(int i=1; i<=n; i++)
        for(int j=1; j<i; j++)
            swap(grid[i][j], grid[j][i]);
    ans += retVal(grid, b);

    cout << (ans >= 1e18 ? -1 : ans) << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}