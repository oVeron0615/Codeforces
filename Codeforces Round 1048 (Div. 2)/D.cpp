#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, q; cin >> n >> q;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];

    stack<int> st;
    vector<int> max_l_idx(n+1);
    for(int i=1; i<=n; i++)
    {
        while(!st.empty() && a[st.top()] < a[i]) st.pop();
        max_l_idx[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    vector<int> min_r_idx(n+1);
    for(int i=n; i>=1; i--)
    {
        while(!st.empty() && a[st.top()] > a[i]) st.pop();
        min_r_idx[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }

    vector<int> L(n+1, 0);
    for(int i=1; i<=n; i++)
    {
        if(min_r_idx[i] == 0 || max_l_idx[i] == 0) continue;
        L[min_r_idx[i]] = max(L[min_r_idx[i]], max_l_idx[i]);
    }
    for(int i=2; i<=n; i++) L[i] = max(L[i], L[i-1]);
    
    while(q--)
    {
        int l, r; cin >> l >> r;
        if(l <= L[r]) cout << "NO\n";
        else cout << "YES\n";
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}