#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, q; cin >> n >> q;

    vector<int> p(n+1), idx(n+1);
    for(int i=1; i<=n; i++) 
    {
        cin >> p[i];
        idx[p[i]] = i;
    }

    while(q--)
    {
        int l, r, k; cin >> l >> r >> k;

        int small_num_cnt = k - 1, big_num_cnt = n - k;
        int swap_to_small = 0, swap_to_big = 0;

        while(l <= r)
        {
            int m = (l + r) / 2;
            if(m < idx[k])
            {
                if(p[m] < k) small_num_cnt--;
                else swap_to_small++;
                l = m + 1;
            }
            else if(m > idx[k])
            {
                if(p[m] > k) big_num_cnt--;
                else swap_to_big++;
                r = m - 1;
            }
            else break;
        }

        if(l > r || swap_to_big > big_num_cnt || swap_to_small > small_num_cnt) cout << -1 << " ";
        else cout << max(swap_to_big, swap_to_small) * 2 << " ";
    }
    cout << "\n";
}   

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}