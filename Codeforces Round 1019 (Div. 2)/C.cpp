#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    ll n, k; cin >> n >> k;
    vector<int> a(n+1), psum(n+1);
    for(int i=1; i<=n; i++) 
    {
        int ai; cin >> ai;
        a[i] = (ai <= k ? 1 : -1);
        psum[i] = psum[i-1] + a[i];
    }

    bool is_ans = false;
    int min_pos_psum = INT_MAX;
    int min_psum = INT_MAX, max_psum = INT_MIN;

    for(int r=2; r<n; r++)
    {
        if(psum[r-1] >= 0) min_pos_psum = min(min_pos_psum, psum[r-1]);
        min_psum = min(min_psum, psum[r-1]);
        max_psum = max(max_psum, psum[r-1]);

        if(psum[n] - psum[r] >= 0)
        {
            if(max_psum >= 0 || psum[r] - min_psum >= 0) is_ans = true;
        }
        else
        {
            if(min_pos_psum <= psum[r]) is_ans = true;
        }
    }

    cout << (is_ans ? "YES\n" : "NO\n");
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}