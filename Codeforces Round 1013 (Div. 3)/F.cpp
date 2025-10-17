#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 2001;
const ll MOD = 998244353;
ll dp[SZ][SZ][2]; //dp[i][j][k] : 좌표 (i, j)에서 row i에서 hold한 횟수가 k일 때, 해당 좌표에 도달할 경우의 수
ll sum[SZ][SZ]; //부분 합
char board[SZ][SZ];

void solve()
{
    int n, m, d; cin >> n >> m >> d;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> board[i][j];
            dp[i][j][0] = dp[i][j][1] = 0;
            sum[i][j] = 0;
        }
    }
    
    for(int i=n; i>=1; i--)
    {
        for(int k=0; k<2; k++)
        {
            for(int j=1; j<=m; j++)
            {
                if(board[i][j] == '#') continue;
                dp[i][j][k] = ((i == n ? 1 : (MOD + sum[i+1][min(m, j+d-1)] - sum[i+1][max(0, j-d)]) % MOD) 
                    + (k == 0 ? 0 : (MOD * 2 + sum[i][min(m, j+d)] - sum[i][max(0, j-d-1)] - dp[i][j][0]) % MOD)) % MOD;
            }
            for(int j=1; j<=m; j++) sum[i][j] = (sum[i][j-1] + dp[i][j][k]) % MOD;
        }
    }

    cout << sum[1][m] << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}