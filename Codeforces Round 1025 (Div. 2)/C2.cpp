#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n; cin >> n;
    int res;

    cout << "mul " << 9 << "\n";
    cout.flush();
    cin >> res;
    
    cout << "digit" << "\n";
    cout.flush();
    cin >> res;

    cout << "digit" << "\n";
    cout.flush();
    cin >> res;

    cout << "add " << n - 9 << "\n";
    cout.flush();
    cin >> res;

    cout << "!\n";
    cout.flush();
    cin >> res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}