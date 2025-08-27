#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, a, b; cin >> n >> a >> b;
    if(n % 2 == b % 2)
    {
        if(b % 2 == a % 2) cout << "YES\n";
        else
        {
            if(a <= b) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    else cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}