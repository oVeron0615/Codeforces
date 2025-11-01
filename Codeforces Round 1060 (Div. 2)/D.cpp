#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2 * 1e5;
vector<int> graph[MAXN + 1];
int depth[MAXN + 1];
int n;

void DFS(int u, int p)
{
    depth[u] = depth[p] + 1;
    for(int v : graph[u])
        if(v != p) DFS(v, u);
}

void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++) graph[i].clear();

    for(int i=1; i<n; i++)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    DFS(n, 0);

    vector<int> leaf(n);
    for(int i=0; i<n; i++) leaf[i] = i + 1;
    sort(leaf.begin(), leaf.end(), [&](int a, int b){
        return depth[a] > depth[b];});

    bool check = depth[1] % 2;
    vector<string> ans;
    for(int u : leaf)
    {
        if(u == n) continue;

        ans.push_back("1"); check = !check;
        if(depth[u] % 2 == check)
        {
            ans.push_back("1");
            check = !check;
        }

        ans.push_back("2 " + to_string(u));
    }

    cout << ans.size() << "\n";
    for(string a : ans) cout << a << "\n";
    cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}