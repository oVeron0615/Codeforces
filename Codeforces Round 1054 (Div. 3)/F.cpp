#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll sum_1toN(ll N) { return N * (N + 1) / 2; }

void solve()
{
    ll h, d; cin >> h >> d;

    ll l = 0, r = d;
    ll ans;
    while(l <= r)
    {
        ll m = (l + r) / 2;
        ll quo = d / (m + 1), rem = d % (m + 1);

        if(sum_1toN(quo + 1) * rem + sum_1toN(quo) * (m + 1 - rem) < h + m) ans = m, r = m - 1;
        else l = m + 1;
    }
    cout << ans + d << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}

//쉬는 횟수는 [0, d] 사이에서 제한되어 있으므로, 몇 번 쉬는지에 따른 최소 소비 체력을 이동하면서 얻은 체력과 비교하면 된다.
//이분 탐색을 통해 문제를 해결한다. 구현에 유의한다.