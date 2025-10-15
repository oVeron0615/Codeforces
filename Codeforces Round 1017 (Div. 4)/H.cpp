#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, q; cin >> n >> q;
    map<int, vector<int>> num_idx; //num이 등장하는 index를 저장

    for(int i=1; i<=n; i++)
    {
        int ai; cin >> ai;
        num_idx[ai].push_back(i);
    }

    while(q--)
    {
        int k, l, r; cin >> k >> l >> r;
        vector<pii> idx_num;

        auto cal_idx_num = [&](int val)
        {
            int val_idx = lower_bound(num_idx[val].begin(), num_idx[val].end(), l) - num_idx[val].begin();
            if(val_idx != num_idx[val].size() && num_idx[val][val_idx] <= r)
                idx_num.push_back({num_idx[val][val_idx], val});
        };

        for(int i=1; i*i<=k; i++) //k의 약수가 구간 [l, r]에서 처음 등장하는 위치를 idx_num에 저장
        {
            if(k % i) continue;
            cal_idx_num(i);
            if(i * i != k) cal_idx_num(k / i);
        }

        sort(idx_num.begin(), idx_num.end());

        ll ans = 0, cur_idx = l;
        for(auto [idx, num] : idx_num)
        {
            ans += (ll)k * (idx - cur_idx);
            while(k % num == 0) k /= num;
            cur_idx = idx;
        }
        ans += k * (r - cur_idx + 1);
        cout << ans << "\n";
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}