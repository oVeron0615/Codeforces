#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100'001;
bool sieve[MAXN];
vector<int> prime;

void solve()
{
    int n; cin >> n;
    vector<int> ans(n+1);
    for(int i=1; i<=n; i++) ans[i] = i;

    for(int p : prime)
    {
        int prev = p, next = p * 2;
        while(next <= n)
        {
            if(ans[next] == next)
            {
                swap(ans[prev], ans[next]);
                prev = next;
            }
            next += p;
        }
    }

    for(int i=1; i<=n; i++) cout << ans[i] << " ";
    cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    sieve[1] = true;
    for(int i=2; i<MAXN; i++)
    {
        if(sieve[i]) continue;
        for(int j=i*2; j<MAXN; j+=i)
            sieve[j] = true;
        prime.push_back(i);
    }
    reverse(prime.begin(), prime.end());

    int T; cin >> T;
    while(T--) solve();
}