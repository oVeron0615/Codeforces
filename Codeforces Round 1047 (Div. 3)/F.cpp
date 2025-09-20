#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n; cin >> n;
    vector<int> a(n+1), b(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];

    vector<int> st;
    vector<int> max_l_idx(n+1);
    for(int i=1; i<=n; i++)
    {
        int l = 0, r = st.size()-1;
        int res = 0;
        while(l <= r)
        {
            int m = (l + r) / 2;
            if(a[st[m]] < max(a[i], b[i])) r = m - 1;
            else res = max(res, m), l = m + 1;
        }

        max_l_idx[i] = r == -1 ? 0 : st[res];

        while(!st.empty() && a[st.back()] < a[i]) st.pop_back();
        st.push_back(i);
    }

    ll ans = 0;
    for(ll i=1; i<=n; i++)
    {
        if(a[i] == b[i]) ans += i * (n - i + 1);
        else ans += max_l_idx[i] * (n - i + 1);
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