#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) v[i] = i + 1;

    random_device rd;
    mt19937 g(rd());
    shuffle(v.begin(), v.end(), g);

    int p1 = v[0], p2 = v[1], p3 = v[2];
    while(p3 != 0)
    {
        cout << "? " << p1 << " " << p2 << " " << p3 << "\n";
        cout.flush();

        int p; cin >> p;
        if(p == 0)
        {
            cout << "! " << p1 << " " << p2 << " " << p3 << "\n";
            cout.flush();
            return;
        }
        
        int x = rd() % 3;
        switch(rd() % 3)
        {
            case 0: p1 = p; break;
            case 1: p2 = p; break;
            default: p3 = p;
        }
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}