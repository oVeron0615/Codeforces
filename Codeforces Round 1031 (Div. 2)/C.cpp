#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, m, k; cin >> n >> m >> k;
    vector<vector<char>> board(n+1, vector<char>(m+1));
    vector<vector<int>> sum(n+1, vector<int>(m+1));

    for(int i=1; i<=n; i++)
    {
        int psum = 0;
        for(int j=1; j<=m; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 'g') psum++;
            sum[i][j] = sum[i-1][j] + psum;
        }
    }

    int min_lost_gold = sum[n][m];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(board[i][j] == '.')
            {
                int bi = min(i + k - 1, n), bj = min(j + k - 1, m);
                int si = max(i - k, 0), sj = max(j - k, 0);
                min_lost_gold = min(min_lost_gold, sum[bi][bj] + sum[si][sj] - sum[bi][sj] - sum[si][bj]);
            }
        }
    }

    cout << sum[n][m] - min_lost_gold << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}