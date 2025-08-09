#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MAXN = 200'001, MOD = 1'000'000'007;
vector<int> graph[MAXN];
int n, m;

ll f(ll n)
{
    ll ret = 1;
    for(ll i=1; i<=n; i++) ret *= i, ret %= MOD;
    return ret;
}

void solve()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++) graph[i].clear();

    for(int i=1; i<=m; i++)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if(n <= m)
    {
        cout << 0 << "\n";
        return;
    }

    ll ans = 1;
    int allLeafCnt = 0;
    for(int u=1; u<=n; u++)
    {
        if(graph[u].size() == 1) allLeafCnt++;

        ll nodeLeafCnt = 0;
        for(int v : graph[u])
            if(graph[v].size() == 1) nodeLeafCnt++;
        if(graph[u].size() - nodeLeafCnt > 2) ans = 0; //리프 노드가 아닌 주변 노드들 개수가 3 이상이면 안 된다.
        
        ans *= f(nodeLeafCnt), ans %= MOD;
    }

    if(allLeafCnt < n-1) ans *= 4;
    else ans *= 2;
    ans %= MOD;
    cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}