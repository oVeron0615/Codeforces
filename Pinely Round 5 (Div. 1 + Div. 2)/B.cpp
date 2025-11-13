#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

void solve()
{
    int n; cin >> n;
    const int INF = 1e9;
    int mxSum = -INF, mnSum = INF, mxSub = -INF, mnSub = INF;
    int mxI = -INF, mnI = INF, mxJ = -INF, mnJ = INF;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            char c; cin >> c;
            if(c == '#')
            {
                mxSum = max(mxSum, i + j);
                mnSum = min(mnSum, i + j);
                mxSub = max(mxSub, i - j);
                mnSub = min(mnSub, i - j);
                mxI = max(mxI, i);
                mnI = min(mnI, i);
                mxJ = max(mxJ, j);
                mnJ = min(mnJ, j);
            }
        }
    }

    if((mxI - mnI <= 1 && mxJ - mnJ <= 1) || mxSum - mnSum <= 1 || mxSub - mnSub <= 1) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}