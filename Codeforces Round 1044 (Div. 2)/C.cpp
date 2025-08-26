#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    vector<int> lv[501];
    int mx = 0;

    int n; cin >> n;
    for(int i=1; i<=n; i++)
    {
        cout << "? " << i << " " << n << " ";
        for(int j=1; j<=n; j++) cout << j << " ";
        cout << "\n";
        cout.flush();

        int res; cin >> res;
        lv[res].push_back(i);
        mx = max(mx, res);
    }

    int idx = mx-1;
    int u = lv[mx][0];
    vector<int> ans;
    ans.push_back(u);

    while(idx >= 1)
    {
        for(int v : lv[idx])
        {
            cout << "? " << u << " " << 2 << " " << u << " " << v << "\n";
            cout.flush();

            int res; cin >> res;
            if(res == 1) continue;

            ans.push_back(v);
            u = v; idx--;
            break;
        }
    }

    cout << "! " << ans.size() << " ";
    for(int a : ans) cout << a << " ";
    cout << "\n";
    cout.flush();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}