#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1e9 + 7;
const ll inv2 = 500000004;

void solve()
{
    int n; cin >> n;
    string x; cin >> x;

    ll ans = 0;
    for(int i=n-1; i>=1; i--) ans = (ans + (x[i] == '1')) * inv2 % MOD;
    cout << (MOD + n - 1 + ans) % MOD << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}

/*
dp[i] : i번째 bit에서 carry가 발생할 확률
x[i] == '0' : dp[i-1] * (1/2) (이전 비트에서 carry * ceil)
x[i] == '1' : (1 - dp[i-1]) * (1/2) + dp[i-1] (carry x * ceil + carry o)
정리하면 dp[i] = (dp[i-1] + (x[i] == '1')) / 2

최상위 비트는 언제나 1이므로, 그 이전 비트에서 carry가 발생하면 n번, 발생하지 않으면 n-1번 연산
기댓값 = n * dp[n - 1] + (n - 1) * (1 - dp[n - 1]) = n - 1 + dp[n - 1]
*/