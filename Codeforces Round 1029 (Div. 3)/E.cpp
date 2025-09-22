#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n; cin >> n;
    vector<int> a(n+1), b(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];

    vector<bool> vis(n+1);
    for(int i=n; i>=1; i--)
    {
        if(vis[a[i]] || vis[b[i]] || (i < n && (a[i] == a[i+1] || b[i] == b[i+1])) || a[i] == b[i])
        {
            cout << i << "\n";
            return;
        }
        if(i < n) vis[a[i+1]] = vis[b[i+1]] = true;
    }
    cout << 0 << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}