#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

const int MAXN = 100'001;
int n, st, en; 
vector<int> graph[MAXN];

void DFS(int u, int p)
{
    for(int v : graph[u])
    {
        if(v == p) continue;
        DFS(v, u);
    }
    cout << u << " ";
}

void solve()
{
    cin >> n >> st >> en;
    for(int i=1; i<=n; i++) graph[i].clear();

    for(int i=1; i<n; i++)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    DFS(en, 0);
    cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}