#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 6001;
int par[MAXN], height[MAXN];

int Find(int x)
{
    if(par[x] == -1) return x;
    return par[x] = Find(par[x]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(height[a] < height[b]) swap(a, b);
    par[b] = a;
    if(height[a] == height[b]) height[a]++;
}

void solve()
{
    int n; cin >> n;

    fill(&par[0], &par[0] + MAXN, -1);
    fill(&height[0], &height[0] + MAXN, 0);
   
    vector<int> ans;
    for(int i=1; i<=n; i++)
    {
        int a, b; cin >> a >> b;
        if(Find(a) != Find(b))
        {
            Union(a, b);
            ans.push_back(i);
        }
    }

    cout << ans.size() << "\n";
    for(int a : ans) cout << a << " ";
    cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}