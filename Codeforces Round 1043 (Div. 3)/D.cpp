#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll retSum(int n)
{
    return n * (n + 1) / 2;
}

void solve()
{
    ll k; cin >> k;
    ll ans = 0;

    ll cur = 9, len = 1, last = 0;
    while(k >= cur * len)
    {
        k -= cur * len;
        last = last * 10 + 9;
        cur *= 10, len++;
    }
    last += k / len;

    string tmp = to_string(last + 1);
    for(int i=0; i<k%len; i++) ans += tmp[i] - '0';

    ll loc = 1; //자릿수
    while(last >= loc)
    {
        ll upper_num = last / (loc * 10);
        ll cur_num = last % (loc * 10) / loc;
        ll lower_num = last % (loc * 10) % loc;

        ans += (upper_num * 45 * loc) + (retSum(cur_num - 1) * loc) + cur_num * (lower_num + 1);
        loc *= 10;
    }
    cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}