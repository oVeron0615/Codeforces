#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1e9 + 7;
const int MAXN = 200'000;

vector<vector<int>> graph(MAXN+1);
vector<int> depth(MAXN+1);

ll sq(int n)
{
    ll res = 1;
    for(int i=1; i<=n; i++) res = res * 2 % MOD;
    return res;
}

void DFS(int u, int p)
{
    depth[u] = depth[p] + 1;
    for(int v : graph[u])
    {
        if(v == p) continue;
        DFS(v, u);
    }
}

void solve()
{
    int n; cin >> n;
    for(int i=1; i<=n; i++) graph[i].clear(), depth[i] = 0;

    for(int i=1; i<n; i++)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int leaf_cnt = 0;
    vector<int> leaf;
    for(int i=2; i<=n; i++)
        if(graph[i].size() == 1) leaf.push_back(i);
    
    if(leaf.size() >= 3) cout << 0 << "\n";
    else if(leaf.size() == 1) cout << sq(n) << "\n";
    else
    {
        int branch = 1;
        for(int i=1; i<=n; i++)
            if(graph[i].size() == 3) branch = i;

        DFS(1, 0);

        int sub = abs(depth[leaf[0]] - depth[leaf[1]]);
        int d = depth[branch] + sub;
        if(sub == 0) cout << sq(d) * 2 % MOD << "\n";
        else cout << (sq(d) + sq(d - 1)) % MOD << "\n";
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}