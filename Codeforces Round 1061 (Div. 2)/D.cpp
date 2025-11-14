#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

void solve()
{
    int n; cin >> n;

    vector<int> idx;
    for(int i=1; i<n; i++) idx.push_back(i);

    int ans = 0;
    for(int i=0; (1 << i)<=n; i++)
    {
        int bit_sum = 0;
        for(int j=1; j<=n; j++)
        {
            if((j & ((1 << i) - 1)) == ans) //j의 하위 i개의 비트가 ans와 같아야 한다.
            {
                if(j & (1 << i)) bit_sum++;
            }
        }

        vector<int> bit0_idx, bit1_idx;
        for(int j : idx)
        {
            cout << "? " << j << " " << (1 << i) << "\n";
            cout.flush();

            int res; cin >> res;
            if(res == 1) bit1_idx.push_back(j);
            else bit0_idx.push_back(j);
        }
        
        if(bit_sum == bit1_idx.size()) idx = bit0_idx;
        else idx = bit1_idx, ans += (1 << i);
    }

    cout << "! " << ans << "\n";
    cout.flush();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}