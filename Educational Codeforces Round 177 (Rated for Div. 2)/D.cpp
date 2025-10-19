#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 998244353;

ll sq(ll n, ll val)
{
	if(n == 0) return 1;

	ll res = sq(n/2, val);
	res *= res, res %= MOD;
	if(n % 2) res *= val, res %= MOD;
	return res;
}

ll f(ll n)
{
    if(n == 0) return 1;

    ll res = 1;
    for(ll i=1; i<=n; i++) res = res * i % MOD;
    return res;
}

void solve()
{
    int sum = 0;
    vector<int> c(26);
    for(int i=0; i<26; i++) 
    {
        cin >> c[i];
        sum += c[i];
    }

    vector<int> dp(sum + 1); 
    dp[0] = 1;
    for(int i=0; i<26; i++)
        for(int j=sum; j>=0; j--)
            if(j-c[i] >= 0 && c[i] > 0) dp[j] = (dp[j] + dp[j-c[i]]) % MOD;
    
    ll ans = f(sum / 2) * f((sum + 1) / 2) % MOD * dp[sum / 2] % MOD;
    for(int i=0; i<26; i++)
        ans = ans * sq(MOD - 2, f(c[i])) % MOD;
    cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}

//dp[i] : 합을 i로 만드는 경우의 수
//dp[sum / 2]를 구하면 각 수들이 홀수, 짝수로 나누어지게 되고, 각 경우마다 수들을 홀수, 짝수 범위에서 배열하면 된다.
//홀수! * 짝수! / (factorial(c[i]))