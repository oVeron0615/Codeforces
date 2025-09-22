#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, q; cin >> n >> q;
    string s; cin >> s;

    int bc = 0, ca = 0, bca = 0, cb = 0, ba = 0, cba = 0;

    while(q--)
    {
        char x, y; cin >> x >> y;
        if(x == 'b' && y == 'c') bc++;
        if(x == 'c' && y == 'a')
        {
            ca++;
            if(bc > bca) bca++;
        }
        if(x == 'c' && y == 'b') cb++;
        if(x == 'b' && y == 'a')
        {
            ba++;
            if(cb > cba) cba++;
        }
    }

    for(int i=0; i<n; i++)
    {
        if(s[i] == 'b')
        {
            if(ba) --ba, cba = min(cba, ba), s[i] = 'a';
            else if(bca) --bc, --ca, --bca, s[i] = 'a';
        }
        else if(s[i] == 'c')
        {
            if(ca) --ca, bca = min(bca, ca), s[i] = 'a';
            else if(cba) --cb, --ba, --cba, s[i] = 'a';
            else if(cb)--cb, cba = min(cba, cb), s[i] = 'b';
        }
    }

    cout << s << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}