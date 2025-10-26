#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int floor(int x, int n)
{
    while(n--) 
    {
        if(x == 0) return x;
        x /= 2;
    }
    return x;
}

int ceil(int x, int m)
{
    while(m--) 
    {
        if(x <= 1) return x;
        x = (x + 1) / 2;
    }
    return x;
}

void solve()
{
    int x, n, m; cin >> x >> n >> m;
    cout << floor(ceil(x, m), n) << " " << ceil(floor(x, n), m) << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}

//x에서 하위 n + m개의 bit 제거 -> 1이 carry될 수도 있고 안 될 수도 있음
//상위 비트를 l이라 할 때, 답은 l 또는 l + 1
//carry가 발생할 때는 ceil일 때이므로, 답은 위의 코드와 같다.