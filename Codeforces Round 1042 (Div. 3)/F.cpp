#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 200'001;
pll A[MAXN], B[MAXN];
ll subB[MAXN];
ll sum0[MAXN], sum1[MAXN];
auto cmp = [](pll p1, pll p2)
{
    return p1.first - p1.second < p2.first - p2.second;
};

void solve()
{
    int n; cin >> n;
    string a, b; cin >> a >> b;

    ll cnt0 = 0, cnt1 = 0;
    for(int i=1; i<=n; i++)
    {
        if(a[i-1] == '0') cnt0++;
        else cnt1++;
        A[i] = {cnt0, cnt1};
    }

    cnt0 = 0, cnt1 = 0;
    for(int i=1; i<=n; i++)
    {
        if(b[i-1] == '0') cnt0++;
        else cnt1++;
        B[i] = {cnt0, cnt1};
        subB[i] = cnt0 - cnt1;
    }

    sort(B + 1, B + n + 1, cmp);
    sort(subB + 1, subB + n + 1);

    for(int i=1; i<=n; i++)
    {
        auto [c0, c1] = B[i];
        sum0[i] = sum0[i-1] + c0;
        sum1[i] = sum1[i-1] + c1;
    }

    ll ans = 0;
    for(int i=1; i<=n; i++)
    {
        auto [c0, c1] = A[i];
        int idx = lower_bound(subB + 1, subB + n + 1, c1 - c0) - subB;
        ans += sum0[idx-1] + c0 * (idx-1) + (sum1[n] - sum1[idx-1]) + c1 * (n-idx+1);
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