#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n; cin >> n;
    for(int i=1; i<n; i++)
    {
        for(int j=1; i+j<=n; j++)
        {
            cout << j << " " << i + j << "\n";
            cout.flush();

            int res; cin >> res;
            if(res) return;
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

//배터리 개수를 a개라 하면, 배터리 간 거리는 n/a보다는 작을 수밖에 없다.
//따라서 배터리 간 거리를 1~n까지 순회하며 모든 배터리를 완전 탐색하면 된다.