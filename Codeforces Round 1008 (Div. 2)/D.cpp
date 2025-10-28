#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n; cin >> n;
    vector<pair<char, ll>> left_gate(n), right_gate(n);

    for(int i=0; i<n; i++)
    {
        char cl, cr;
        ll xl, xr;
        cin >> cl >> xl >> cr >> xr;
        left_gate[i] = {cl, xl}, right_gate[i] = {cr, xr};
    }

    ll ans = 0;
    vector<ll> dp_left(n+1), dp_right(n+1);
    dp_left[n] = dp_right[n] = 1;
    for(int i=n-1; i>=0; i--)
    {
        auto [cl, xl] = left_gate[i];
        auto [cr, xr] = right_gate[i];

        ll mx = max(dp_left[i+1], dp_right[i+1]);

        dp_left[i] = dp_left[i+1] + (xl - 1) * (cl == 'x' ? mx : 0);
        dp_right[i] = dp_right[i+1] + (xr - 1) * (cr == 'x' ? mx : 0);
        if(cl == '+') ans += xl * mx;
        if(cr == '+') ans += xr * mx;
    }
    ans += dp_left[0] + dp_right[0];
    cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}

/*
dp[i] = 사람 한 명이 [i ~ n-1) gate를 지날 때 만들 수 있는 사람의 최댓값
기저 사례 : dp[n] = 1(어떠한 gate도 지나지 않으면 사람 한 명이 그대로 남는다.)
+ : 사람이 만들어지지 않으므로, [i-1 ~ n-1) gate를 지날 때와 동일
x : gate 값을 a라 할 때, (a - 1)명의 사람을 만들 수 있다. 따라서 왼쪽 gate와 오른쪽 gate를 선택할 때 최댓값을 구해 곱하면 된다.
*/