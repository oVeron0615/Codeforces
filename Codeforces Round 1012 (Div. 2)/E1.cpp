#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, k; cin >> n >> k;

    vector<ll> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    int ans = 1;
    int seq = 0;
    ll sum = 0; 
    for(int i=0; i<2*n; i++)
    {
        sum += a[i % n], a[i % n] = 0;
        int mn = min(sum, b[i % n]);
        sum -= mn, b[i % n] -= mn;

        if(sum == 0) 
        {
            ans = max(ans, seq + 1);
            seq = 0;
        }
        else seq++;
    }

    cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}

//a[i]가 몇 번의 operation을 거쳐야 0이 되는지 판단.
//a[i]의 누적 합을 구해가며 operation을 진행하면 누적 합이 0이 되는 경우가 존재하는데, 이때가 바로 그 "몇 번"이다.