#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, m, l; cin >> n >> m >> l;
    
    vector<int> A(l+1);
    for(int i=1; i<=l; i++) cin >> A[i];

    vector<vector<int>> graph(n+1);
    for(int i=1; i<=m; i++)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<vector<int>> dist(2, vector<int>(n+1, INT_MAX));
    dist[0][1] = 0;

    queue<pii> qu;
    qu.push({0, 1});
    while(!qu.empty())
    {
        auto [p, u] = qu.front(); qu.pop();
        for(int v : graph[u])
        {
            if(dist[!p][v] != INT_MAX) continue;
            dist[!p][v] = dist[p][u] + 1;
            qu.push({!p, v});
        }
    }

    int sum = 0;
    int min_odd = INT_MAX;
    for(int i=1; i<=l; i++)
    {
        sum += A[i];
        if(A[i] % 2) min_odd = min(min_odd, A[i]);
    }

    for(int i=1; i<=n; i++)
    {
        bool is_ans = false;
        for(int p=0; p<2; p++)
        {
            int s = sum - (p == sum % 2 ? 0 : min_odd);
            if(dist[p][i] <= s) is_ans = true;
        }

        cout << is_ans;
    }
    cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}