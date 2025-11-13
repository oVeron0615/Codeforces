#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

void solve()
{
    int n, k, x; cin >> n >> k >> x;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    v.push_back(-1e9);
    v.push_back(1e9);
    sort(v.begin(), v.end());

    n += 2;

    int d = 0;
    int l = 0, r = x;
    while(l <= r)
    {
        int m = (l + r) / 2;
        v[0] = -m, v[n-1] = x + m;

        int sum = 0;
        for(int i=1; i<n; i++)
        {
            sum += max(0, (v[i] - m) - (v[i-1] + m) + 1);
        }

        if(sum >= k) d = m, l = m + 1;
        else r = m - 1;
    }

    v[0] = -d, v[n-1] = x + d;
    int j = 0;
    for(int i=1; i<n; i++)
    {
        for(j = max(j, v[i-1] + d); j <= min(v[i] - d, x); j++)
        {
            cout << j << " ";
            if(--k == 0)
            {
                cout << "\n";
                return;
            }
        }
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}

/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

void solve()
{
    int n, k, x; cin >> n >> k >> x;

    vector<int> friends(n);
    for(int i=0; i<n; i++) cin >> friends[i];
    sort(friends.begin(), friends.end());

    priority_queue<tii> pq;
    pq.push({friends[0], 0, 1});
    pq.push({x - friends[n-1], x, -1});
    for(int i=0; i<n; i++) pq.push({0, friends[i], 1});
    for(int i=1; i<n; i++)
    {
        int m = (friends[i] + friends[i-1]) / 2;
        pq.push({m - friends[i-1], m, -1});
        pq.push({friends[i] - (m + 1), m + 1, 1});
    }

    set<int> check;
    while(k) 
    {
        auto [dist, loc, mov] = pq.top(); pq.pop();
        if(check.find(loc) == check.end()) 
        {
            cout << loc << " ";
            k--;
        }
        check.insert(loc);
        pq.push({dist - 1, loc + mov, mov});
    }
    cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}
*/