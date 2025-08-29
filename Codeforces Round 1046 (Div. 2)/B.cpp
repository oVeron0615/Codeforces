#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int mn = 1, mx = n;
    vector<int> ans(n);

    int cnt = 0;
    for(int i=0; i<s.size(); i++)   
    {
        if(s[i] == '0') ans[i] = mx--;
        else ans[i] = mn++;

        if(s[i] == '1')
        {
            if(++cnt == k)
            {
                cout << "NO\n";
                return;
            }
        }
        else cnt = 0;
    }

    cout << "YES\n";
    for(int i=0; i<n; i++) cout << ans[i] << " ";
    cout << "\n";
    
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}