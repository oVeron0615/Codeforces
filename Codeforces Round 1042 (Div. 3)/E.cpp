#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 200'001;
int a[MAXN], b[MAXN];
int n;

void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];

    for(int i=1; i<=n; i++)
    {
        if(i == n)
        {
            if(a[i] != b[i])
            {
                cout << "NO\n";
                return;
            }
        }
        else
        {
            if(a[i] != b[i] && (a[i] ^ a[i+1]) != b[i] && (a[i] ^ b[i+1]) != b[i])
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}