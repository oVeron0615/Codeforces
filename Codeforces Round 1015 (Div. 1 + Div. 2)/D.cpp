#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, m, k; cin >> n >> m >> k;
    int p = n/(m+1);

    for(int i=0; i<n; i++) cout << i % max(p, k) << " ";
    cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}

//특정 수가 m+1개는 있어야 m번의 제거에도 숫자가 남아있을 수 있다.
//따라서 m+1개의 수가 크기 n의 배열에 위치시킬 수 있는 최소 간격의 최댓값(n/(m+1) = p)를 k와 비교한다.
//같은 수의 간격이 k보다 작으면 안 되므로, 수들을 max(p, k)의 간격으로 배치시킨다.