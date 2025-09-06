#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, k; cin >> n >> k;

    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];

    vector<int> sortedA = a;
    sort(sortedA.begin() + 1, sortedA.end());

    vector<int> palin;
    for(int i=1; i<=n; i++)
        if(a[i] <= sortedA[k-1]) palin.push_back(a[i]);
    
    int sz = palin.size();
    int l = 0, r = palin.size() - 1;
    while(l < r)
    {
        if(palin[l] == palin[r]) l++, r--;
        else
        {
            if(palin[l] == sortedA[k-1]) sz--, l++;
            else if(palin[r] == sortedA[k-1]) sz--, r--;
            else
            {
                cout << "NO\n";
                return;
            }
        }
    }

    if(sz >= k-1) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}