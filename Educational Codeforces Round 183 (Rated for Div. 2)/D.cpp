#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    const int MAXN = 31;
    int n, k; cin >> n >> k;
    int dp[MAXN][MAXN*MAXN] = {}, track[MAXN][MAXN*MAXN] = {};
    //dp[i][j] : i까지 수를 배열했을 때 역순열 구간이 j개 있는지 여부
    //track[i][j] : 추가한 오름차순 블록의 크기

    dp[0][0] = true;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n*(n-1)/2; j++)
        {
            if(!dp[i][j]) continue;
            for(int x=1; i+x<=n; x++)
            {
                dp[i+x][j+i*x] = true; //[i+1 ~ i+x]까지 새로운 오름차순 블록을 추가한다면, 역순열 구간의 개수는 i*x개 만큼 증가한다.
                track[i+x][j+i*x] = x;
            }
        }
    }

    if(!dp[n][k])
    {
        cout << "0\n";
        return;
    }

    int cur_n = n, cur_k = k;
    stack<int> st;
    while(cur_n > 0)
    {
        int x = track[cur_n][cur_k];
        st.push(x);
        cur_n -= x, cur_k -= cur_n * x;
    }

    int ans = n;
    while(!st.empty())
    {
        int x = st.top(); st.pop();
        ans -= x;
        for(int i=ans+1; i<=ans+x; i++) cout << i << " ";
    }
    cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}