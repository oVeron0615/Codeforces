#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1e9 + 7;

void solve()
{
    ll a, b, k; cin >> a >> b >> k;
    ll n = (a - 1) * k + 1;

    vector<ll> inv(a+1);
    inv[1] = 1;
    for(ll i=2; i<=a; i++) inv[i] = (MOD - MOD / i * inv[MOD % i] % MOD) % MOD;
    
    ll m = 1;
    for(ll i=1; i<=a; i++) m = m * ((n - i + 1) % MOD) % MOD * inv[i] % MOD;
    m = (m * k % MOD * (b-1) % MOD + 1) % MOD;
    n %= MOD;

    cout << n << " " << m << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}

/*
i * inv[i] = 1 (mod M)
M = (M / i) * i + (M mod i) (mod M)     <-- 양변에 inv[i] 곱하기
M * inv[i] = (M / i) * i * inv[i] + (M mod i) * inv[i] (mod M)
0 = M / i + (M mod i) * inv[i]
inv[i] * (M mod i) = - (M / i) (mod M)  <-- 양변에 inv[M mod i] 곱하기
inv[i] = - (M / i) * inv[M mod i] (mod M)
*/