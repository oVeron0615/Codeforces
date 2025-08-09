#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, x; cin >> n >> x;
    string s; cin >> s;
    
    x--;
    int l = x, r = x;

    while(l >= 0 && s[l] == '.') l--;
    while(r < n && s[r] == '.') r++;

    if(l == -1 && r == n || x == 0 || x == n-1) cout << 1 << "\n";
    else 
    {
        if(l + 2 < n - r + 1) l = x - 1;
        else r = x + 1;
        cout << min(l + 2, n - r + 1) << "\n";
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}

/*
Hamid의 위치를 기준으로, 왼쪽과 오른쪽에 있는 가장 가까운 벽을 구한다.
구한 벽의 위치가 끝단에 더 가까운 방향으로 Hamid가 이동해야 최적이다. Mani가 Hamid의 이동 방향의 빈 공간에 벽을 세울 것이기 때문이다.
Hamid의 위치가 양 끝에 있거나, 벽이 아예 없으면 한 번의 이동으로 탈출할 수 있다.
그렇지 않다면, Mani는 구한 벽의 위치가 끝단에 더 가까운 방향에, Hamid의 바로 앞에 벽을 세울 것이다.
*/