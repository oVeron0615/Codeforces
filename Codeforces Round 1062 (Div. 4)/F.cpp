#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 200'001;
vector<int> graph[MAXN];
vector<ll> subSize(MAXN);

void DFS(int u, int p)
{
    for(int v : graph[u])
    {
        if(p == v) continue;
        DFS(v, u);
        subSize[u] += subSize[v];
    }
}

void solve()
{
    int n, k; cin >> n >> k;
    for(int i=1; i<=n; i++)
    {
        graph[i].clear();
        subSize[i] = 1;
    } 

    for(int i=1; i<n; i++)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    DFS(1, 0);

    ll ans = 0;
    for(int i=1; i<=n; i++)
    {
        if(subSize[i] >= k) ans += n - subSize[i];
        if(n - subSize[i] >= k) ans += subSize[i];
    }
    cout << ans + n << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}