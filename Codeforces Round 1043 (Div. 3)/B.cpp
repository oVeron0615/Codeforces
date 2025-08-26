#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    ll n; cin >> n;
    ll a = 11;
    vector<ll> ans;

    while(a <= n)
    {
        if(n % a == 0) ans.push_back(n / a);
        a = (a-1) * 10 + 1;
    }

    cout << ans.size() << "\n";
    for(int i=ans.size()-1; i>=0; i--) cout << ans[i] << " ";
    if(ans.size()) cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}