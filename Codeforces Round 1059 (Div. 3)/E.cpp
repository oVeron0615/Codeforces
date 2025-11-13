#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> a(n);
    vector<bool> vis(n+1);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        vis[a[i]] = true;
    }

    int notVis = 0;
    for(int i=1; i<=n; i++)
    {
        if(!vis[i]) notVis = i;
    }

    vector<int> ans;
    if(!notVis) ans = {a[0], a[1], a[2]};
    else
    {
        for(int i=1; i<=n; i++)
        {
            if(i != a[n-1] && i != notVis)
            {
                ans = {notVis, i, a[n-1]};
            }
        }
    }

    for(int i=0; i<k; i++) cout << ans[i % 3] << " ";
    cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}