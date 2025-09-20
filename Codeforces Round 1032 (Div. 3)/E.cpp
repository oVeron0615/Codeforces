#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    string l, r; cin >> l >> r;
    int sz = l.length();

    int ans = 0;
    bool prev_sub_one = false;
    for(int i=0; i<sz; i++)
    {
        if(prev_sub_one)
        {
            if(l[i] == '9' && r[i] == '0') ans += 1;
            else break;
        }
        else
        {
            if(r[i] - l[i] == 0) ans += 2;
            else if(r[i] - l[i] == 1)
            {
                prev_sub_one = true;
                ans += 1;
            }
            else break;
        }
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