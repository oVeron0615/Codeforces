#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

const int MAXN = 200'001;
vector<int> a(MAXN*4);
vector<int> psum(MAXN*4);
ll n, l, r;

void solve()
{
    cin >> n >> l >> r;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        psum[i] = psum[i-1] ^ a[i];
    }

    if(n % 2 == 0) 
    {
        n++;
        a[n] = psum[n/2];
        psum[n] = psum[n-1] ^ a[n];
    }

    for(int i=n+1; i<=n*2; i++) 
    {
        a[i] = psum[i/2];
        psum[i] = psum[i-1] ^ a[i];
    }

    int ans = 0;
    while(true)
    {
        if(l <= n * 2) 
        {
            ans ^= a[l];
            break;
        }
        ans ^= psum[n];
        if((l / 2 - n) % 2 == 0) break;
        l /= 2;
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