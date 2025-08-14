#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 200'001;
vector<int> graph[MAXN];
int n;

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

    int allLeafCnt = 0, maxLeafCnt = 0;
    for(int u=1; u<=n; u++)
    {
        int leafCnt = 0;
        for(int v : graph[u])
        {
            if(graph[v].size() == 1) 
            {
                allLeafCnt++;
                leafCnt++;
            }
        }
        maxLeafCnt = max(maxLeafCnt, leafCnt);
    }

    if(n == 2) cout << 0 << "\n";
    else cout << allLeafCnt - maxLeafCnt << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}