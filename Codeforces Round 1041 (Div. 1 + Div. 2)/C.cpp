#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    const int MAXN = 200'001;
    const ll INF = 1e18;
    ll a[MAXN], b[MAXN];
    pll ab[MAXN];

    int n, k; cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];

    ll ans = 0;
    for(int i=1; i<=n; i++) 
    {
        if(a[i] > b[i]) swap(a[i], b[i]);
        ab[i] = {a[i], b[i]};
        ans += abs(a[i] - b[i]);
    }
    sort(ab + 1, ab + n + 1);

    for(int i=1; i<n; i++)
    {
        auto [a1, b1] = ab[i];
        auto [a2, b2] = ab[i+1];

        if(b1 >= a2) //이러한 케이스가 존재할 경우, Ali는 a1, b1, a2, b2만 계속 선택하면 된다.
        {
            cout << ans << "\n";
            return;
        }
    }

    ll mnPlus = INF;
    for(int i=1; i<n; i++) //그러한 케이스가 없을 경우, 두 index를 바꿨을 때 최소가 되는 값을 찾는다.
    {
        auto [a1, b1] = ab[i];
        auto [a2, b2] = ab[i+1];
        mnPlus = min(mnPlus, 2 * (a2 - b1));
    }
    cout << ans + mnPlus << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}