#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n; cin >> n;
    string a; cin >> a;
    int m; cin >> m;
    string b, c; cin >> b >> c;

    for(int i=0; i<m; i++)
    {
        if(c[i] == 'V') a = b[i] + a;
        else a += b[i];
    }
    cout << a << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}