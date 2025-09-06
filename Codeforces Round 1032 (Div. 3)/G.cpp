#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    ll n; cin >> n;
    vector<ll> sub(n+1);

    ll cnt0 = 0, cnt1 = 0;
    for(int i=1; i<=n; i++)
    {
        char c; cin >> c;
        if(c == '0') cnt0++;
        else cnt1++;
        sub[i] = cnt0 - cnt1;
    }
    sort(sub.begin(), sub.end());

    ll sum = 0;
    for(int i=0; i<=n; i++)
        sum += sub[i] * (2 * i - n);
    
    cout << (n*(n+1)*(n+2)/6 + sum) / 2 << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}