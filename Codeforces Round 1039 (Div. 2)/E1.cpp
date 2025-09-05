#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 300'001;
int n, k;
int a[MAXN], big[MAXN], sum[MAXN];

void solve()
{
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];

    int ans, ansL, ansR;
    int l = 1, r = n;
    while(l <= r)
    {
        int m = (l + r) / 2;
        int L, R;

        bool check = false;
        int mn = 0, mnIdx = 1;
        for(int i=1; i<=n; i++) 
        {
            sum[i] = sum[i-1] + (a[i] >= m ? 1 : -1);
            if(i >= k && mn > sum[i-k]) mn = sum[i-k], mnIdx = i-k+1;
            if(i >= k && sum[i] - mn >= 0) 
            {
                L = mnIdx, R = i;
                check = true;
            }
        }

        if(check) ans = m, ansL = L, ansR = R, l = m + 1;
        else r = m - 1;
    }
    cout << ans << " " << ansL << " " << ansR << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}