#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct status
{
    int x, y, idx;
};

void solve()
{
    int n; cin >> n;
    vector<status> point(n+1);
    for(int i=1; i<=n; i++)
    {
        int x, y; cin >> x >> y;
        point[i] = {x, y, i};
    }

    sort(point.begin() + 1, point.end(), [](status p1, status p2) {
        return p1.x < p2.x;
    });
    sort(point.begin() + 1, point.begin() + n/2 + 1, [](status p1, status p2) {
        return p1.y < p2.y;
    });
    sort(point.begin() + n/2 + 1, point.end(), [](status p1, status p2) {
        return p1.y < p2.y;
    });

    for(int i=1; i<=n/2; i++)
        cout << point[i].idx << " " << point[n-i+1].idx << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}