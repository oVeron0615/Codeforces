#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void solve()
{
    ll n, k; cin >> n >> k;
    vector<ll> p(n+1), d(n+1);
    for(int i=1; i<=n; i++) cin >> p[i];
    for(int i=1; i<=n; i++) cin >> d[i];

    int q; cin >> q;
    while(q--)
    {
        ll curl; cin >> curl;

        int curI = lower_bound(p.begin() + 1, p.end(), curl) - p.begin();
        if(curI == n + 1)
        {
            cout << "YES\n";
            continue;
        }

        vector<vector<bool>> vis(2, vector<bool>(n+1));
        bool dir = true;
        ll curt = p[curI] - curl;

        while(true)
        {
            if(curt >= d[curI] && (curt - d[curI]) % k == 0)
            {
                if(vis[dir][curI])
                {
                    cout << "NO\n";
                    break;
                }
                vis[dir][curI] = true;
                dir = !dir;
            }

            int nxI = dir ? curI + 1 : curI - 1;
            if(nxI > n || nxI < 1)
            {
                cout << "YES\n";
                break;
            }
            curt += abs(p[curI] - p[nxI]);
            curI = nxI;
        }
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}