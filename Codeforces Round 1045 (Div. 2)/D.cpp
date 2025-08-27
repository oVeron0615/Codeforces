#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 200'001;
int n;
vector<int> graph[MAXN];
int dist[MAXN], par[MAXN];

void DFS(int u, int p)
{
    dist[u] = dist[p] + 1;
    par[u] = p;
    for(int v : graph[u])
    {
        if(v == p) continue;
        DFS(v, u);
    }
}

void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++) 
    {
        graph[i].clear();
        dist[i] = par[i] = 0;
    }

    for(int i=1; i<n; i++)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    //지름의 양 끝 점 root와 leaf 구하기
    DFS(1, 0);
    int root = max_element(dist + 1, dist + n + 1) - dist;
    DFS(root, 0);
    int leaf = max_element(dist + 1, dist + n + 1) - dist;

    //지름의 경로 구하기
    vector<int> path;
    path.push_back(leaf);
    while(leaf != root)
    {
        leaf = par[leaf];
        path.push_back(leaf);
    }

    //간선이 지름인 것과 아닌 것을 택한다. 지름이 아닌 간선에 붙은 노드에 지름이 포함된 간선을 붙이면, 무조건 지름이 1 늘어난다.
    for(int i=0; i<path.size(); i++)
    {
        int u = path[i];
        for(int v : graph[u])
        {
            if(i > 0 && v == path[i-1]) continue;
            if(i < path.size()-1 && v == path[i+1]) continue;
            else
            {
                int a = par[u], b = u, c = v; 
                cout << a << " " << b << " " << c << "\n";
                return;
            }
        }
    }
    cout << -1 << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}