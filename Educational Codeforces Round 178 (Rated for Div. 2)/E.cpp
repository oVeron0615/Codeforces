#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<vector<int>> next_alpha(n+1, vector<int>(k, n));
    vector<int> dp(n+1, 0);
    for(int i=n-1; i>=0; i--)
    {
        next_alpha[i] = next_alpha[i+1];
        dp[i] = dp[*max_element(next_alpha[i].begin(), next_alpha[i].end())] + 1;
        next_alpha[i][s[i]-'a'] = i;
    }

    int q; cin >> q;
    while(q--)
    {
        string t; cin >> t;

        int idx = -1;
        for(char c : t) 
        {
            idx = next_alpha[idx + 1][c - 'a'];
            if(idx == n) break;
        }
        cout << dp[idx] << "\n";
    }
}