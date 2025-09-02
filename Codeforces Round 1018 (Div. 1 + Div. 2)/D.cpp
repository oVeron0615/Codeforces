#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    map<int, int> col, diag;

    int n; cin >> n;
    for(int i=1; i<=n; i++)
    {
        int x, y; cin >> x >> y;
        col[x]++, diag[x+y]++;
    }

    int ansX, ansY;
    for(auto [key, val] : col)
    {
        if(val % 2)
        {
            ansX = key;
            break;
        }
    }
    for(auto [key, val] : diag)
    {
        if(val % 2)
        {
            ansY = key - ansX;
            break;
        }
    }

    cout << ansX << " " << ansY << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}