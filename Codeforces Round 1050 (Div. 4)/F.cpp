#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n; cin >> n;
    vector<vector<int>> a(n);
    for(int i=0; i<n; i++)
    {
        int k; cin >> k;
        a[i].resize(k);
        for(int j=0; j<k; j++) cin >> a[i][j];
    }

    vector<int> ans;
    while(!a.empty())
    {
        sort(a.begin(), a.end());
        for(int aij : a[0]) ans.push_back(aij);

        vector<vector<int>> tmp;
        for(int i=1; i<a.size(); i++)
        {
            if(a[0].size() < a[i].size())
            {
                tmp.push_back(vector<int>());
                for(int j=a[0].size(); j<a[i].size(); j++)
                    tmp.back().push_back(a[i][j]);
            }
        }

        a = tmp;
    }

    for(int x : ans) cout << x << " ";
    cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}