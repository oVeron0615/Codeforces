#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n; cin >> n;
    for(int i=1; i<=n; i++)
    {
        if(i % 2) cout << -1 << " ";
        else
        {
            if(i == n) cout << 2 << " ";
            else cout << 3 << " ";
        }
    }
    cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}