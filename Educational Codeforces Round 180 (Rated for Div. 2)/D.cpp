#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 200'000;
vector<vector<int>> graph(MAXN+1);

void DFS(int u, int p, bool dir)
{
    for(int v : graph[u])
    {
        if(dir) cout << u << " " << v << "\n";
        if(v == p) continue;
        DFS(v, u, !dir);
    }
}

void solve()
{
    int n; cin >> n;

    for(int i=1; i<=n; i++) graph[i].clear();
    for(int i=1; i<n; i++)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int node_deg_2 = 0;
    for(int u=1; u<=n; u++)
    {
        if(graph[u].size() == 2)
            node_deg_2 = u;
    }
    
    if(!node_deg_2) cout << "NO\n";
    else 
    {
        cout << "YES\n";
        cout << node_deg_2 << " " << graph[node_deg_2][0] << "\n";
        DFS(graph[node_deg_2][0], node_deg_2, false);
        DFS(graph[node_deg_2][1], node_deg_2, true);
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}