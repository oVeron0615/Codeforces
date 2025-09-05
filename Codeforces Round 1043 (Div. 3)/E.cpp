#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 200'001;
int n, m, q; 
ll a[SZ], b[SZ];
pii ab[SZ*2];
ll suma[SZ], sumb[SZ], sumab[SZ*2];

void solve()
{
    cin >> n >> m >> q;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=m; i++) cin >> b[i];

    sort(a + 1, a + n + 1, greater<>());
    sort(b + 1, b + m + 1, greater<>());
    
    int aIdx = 0, bIdx = 0;
    int i = 0;
    while(aIdx <= n && bIdx <= m)
    {
        if(a[aIdx+1] > b[bIdx+1]) ab[++i] = {++aIdx, bIdx};
        else ab[++i] = {aIdx, ++bIdx};
    }
    while(aIdx <= n) ab[i++] = {++aIdx, bIdx};
    while(bIdx <= m) ab[i++] = {aIdx, ++bIdx};

    for(int i=1; i<=n; i++) suma[i] = suma[i-1] + a[i];
    for(int i=1; i<=m; i++) sumb[i] = sumb[i-1] + b[i];

    while(q--)
    {
        int x, y, z; cin >> x >> y >> z;
        
        auto [aIdx, bIdx] = ab[z];
        if(aIdx <= x && bIdx <= y) cout << suma[aIdx] + sumb[bIdx] << "\n";
        else if(aIdx <= x) cout << suma[z-y] + sumb[y] << "\n";
        else cout << suma[x] + sumb[z-x] << "\n";
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}