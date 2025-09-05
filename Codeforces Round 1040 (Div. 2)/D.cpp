#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5001;
int n;
int p[MAXN];

void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i];

    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        int cnt1 = 0, cnt2 = 0;
        for(int j=i-1; j>=1; j--) if(p[i] < p[j]) cnt1++;
        for(int j=i+1; j<=n; j++) if(p[i] < p[j]) cnt2++;
        ans += min(cnt1, cnt2);
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