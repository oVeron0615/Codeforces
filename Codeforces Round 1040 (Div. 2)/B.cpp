#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, s; cin >> n >> s;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    int sum = 0;
    for(int i=1; i<=n; i++)
    {
        int ai; cin >> ai;
        sum += ai;
        if(ai == 0) cnt0++;
        if(ai == 1) cnt1++;
        if(ai == 2) cnt2++;
    }

    if(s >= sum && sum + 1 != s) cout << -1 << "\n";
    else
    {
        while(cnt0--) cout << 0 << " ";
        while(cnt2--) cout << 2 << " ";
        while(cnt1--) cout << 1 << " ";
        cout << "\n";
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}