#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void dijkstra(vector<vector<pii>>& graph, vector<int>& dist, int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0, pq.push({dist[s], s});
    while(!pq.empty())
    {
        auto [du, u] = pq.top(); pq.pop();
        if(du > dist[u]) continue;

        for(auto [dv, v] : graph[u])
        {
            if(dist[v] > max(du, dv))
            {
                dist[v] = max(du, dv);
                pq.push({dist[v], v});
            }
        }
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<pii>> graph(n+1);
    while(m--)
    {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }
    
    vector<int> dist_S(n+1, INT_MAX), dist_T(n+1, INT_MAX);
    dijkstra(graph, dist_S, 1);
    dijkstra(graph, dist_T, n);

    int ans = INT_MAX;
    for(int u=1; u<=n; u++)
    {
        for(auto [d, v] : graph[u])
        {
            ans = min(ans, max({dist_S[u], dist_T[v], d}) + d);
        }
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