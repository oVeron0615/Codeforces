#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, m; cin >> n >> m;
    vector<string> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];

    vector<bool> is_exist(n+1);

    int mx_exist = 0;
    for(int i=1; i<=m; i++)
    {
        int exist_cnt = 0;
        for(int j=1; j<=n; j++)
        {
            string bij; cin >> bij;
            if(a[j] == bij)
            {
                is_exist[j] = true;
                exist_cnt++;
            }
        }

        mx_exist = max(mx_exist, exist_cnt);
    }
    
    for(int i=1; i<=n; i++)
    {
        if(!is_exist[i])
        {
            cout << "-1\n";
            return;
        }
    }

    cout << n + (n - mx_exist) * 2 << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}