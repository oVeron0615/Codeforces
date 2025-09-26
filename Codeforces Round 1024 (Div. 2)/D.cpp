#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll inv_cnt(vector<int>& v, int l, int r)
{
    if(l == r) return 0;

    int m = (l + r) / 2;
    ll res = inv_cnt(v, l, m) + inv_cnt(v, m + 1, r);
    vector<int> tmp;

    int L = l, R = m + 1;
    while(L <= m && R <= r)
    {
        if(v[L] < v[R]) tmp.push_back(v[L++]);
        else 
        {
            tmp.push_back(v[R++]);
            res += m + 1 - L;
        }
    }
    while(L <= m) tmp.push_back(v[L++]);
    while(R <= r) tmp.push_back(v[R++]);

    for(int i=l; i<=r; i++) v[i] = tmp[i-l];

    return res;
}

void solve()
{
    int n; cin >> n;
    vector<int> odd_idx, even_idx;
    for(int i=1; i<=n; i++)
    {
        int ai; cin >> ai;
        if(i % 2) odd_idx.push_back(ai);
        else even_idx.push_back(ai);
    }

    ll inv_cnt_odd = inv_cnt(odd_idx, 0, n / 2 - 1 + (n % 2 ? 1 : 0));
    ll inv_cnt_even = inv_cnt(even_idx, 0, n / 2 - 1);

    vector<int> ans;
    for(int i=0; i<n/2; i++) 
    {
        ans.push_back(odd_idx[i]);
        ans.push_back(even_idx[i]);
    }
    if(n % 2) ans.push_back(odd_idx[n/2]);

    if(inv_cnt_odd % 2 != inv_cnt_even % 2) swap(ans[n-1], ans[n-3]);
    for(int a : ans) cout << a << " ";
    cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}