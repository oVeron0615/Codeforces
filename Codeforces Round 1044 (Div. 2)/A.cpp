#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n; cin >> n;
    int cnt[101] = {};
    for(int i=1; i<=n; i++)
    {
        int ai; cin >> ai;
        cnt[ai]++;
    }

    for(int i=1; i<=100; i++)
    {
        if(cnt[i] >= 2)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}