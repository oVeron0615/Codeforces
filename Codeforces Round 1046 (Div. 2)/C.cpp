#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 200'001;
int a[MAXN];
vector<int> loc[MAXN];
int dp[MAXN];
int n;

void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++)
    {
        loc[i].clear();
        dp[i] = 0;
    } 

    int mx = 0;
    for(int i=1; i<=n; i++)
    {
        loc[a[i]].push_back(i);
        int prev = loc[a[i]].size() - a[i];

        if(prev < 0) dp[i] = mx;
        else dp[i] = max(mx, dp[loc[a[i]][prev]-1] + a[i]);

        mx = max(mx, dp[i]);
    }
    cout << mx << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}