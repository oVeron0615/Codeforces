#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int lIdx, rIdx;
char ans[1001];

ll calDef()
{
    ll ret = 0;
    for(int i=0; i<8; i++)
    {
        ll val = (1 << i);
        ret += val * (val + 1) / 2;
    }
    return ret;
}

void solve()
{
    int n; cin >> n;

    cout << "? " << n << " ";
    for(int i=1; i<=n; i++) cout << i << " ";
    cout << "\n";
    cout.flush();

    ll res; cin >> res;
    if(res == 0) lIdx = n, rIdx = 1;
    else
    {
        int l = 1, r = n;
        while(l <= r)
        {
            int m = (l + r) / 2;
            cout << "? " << m << " ";
            for(int i=1; i<=m; i++) cout << i << " ";
            cout << "\n";
            cout.flush();

            ll res; cin >> res;
            if(res) rIdx = m, r = m - 1;
            else l = m + 1;
        }
        lIdx = rIdx - 1;
    }

    for(int i=1; i<=n; i+=8)
    {
        cout << "? " << 8 + ((1 << 8) - 1) * 2 << " ";
        for(int j=0; j<8; j++)
        {
            if(i + j <= n) cout << i + j << " " << rIdx << " ";
            else cout << lIdx << " " << rIdx << " ";

            for(int k=2; k<=(1 << (7 - j)); k++)
                cout << lIdx << " " << rIdx << " ";
            cout << rIdx << " ";
        }
        cout << "\n";
        cout.flush();
        
        ll res; cin >> res;
        ll val = calDef() - res;
        for(int j=0; j<8; j++)
        {
            if(i + j > n) break;
            if(val & (1 << (7 - j))) ans[i + j] = ')';
            else ans[i + j] = '(';
        }
    }

    cout << "! ";
    for(int i=1; i<=n; i++) cout << ans[i];
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