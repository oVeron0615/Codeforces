#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int x1 = 1, y1 = 1, x0 = 1, y0 = 1;
    set<pii> vis;

    int n; cin >> n;
    while(n--)
    {
        int t; cin >> t;
        if(t == 1)
        {
            while(true)
            {
                if((x1 + y1) % 3 != 1 && x1 % 3 && y1 % 3)
                {
                    if((x1 + y1) % 3 == 0 && x1 % 3 == 2 && y1 - 2 > 0)
                    {
                        if(vis.find({x1, y1 - 2}) == vis.end())
                        {
                            vis.insert({x1, y1 - 2});
                            cout << x1 << " " << y1 - 2 << "\n";
                            break;
                        }
                    }
                    if(vis.find({x1, y1}) == vis.end())
                    {
                        vis.insert({x1, y1});
                        cout << x1 << " " << y1 << "\n";
                        break;
                    }
                }

                if(y1 > 1) x1 += 1, y1 -= 1;
                else y1 = x1 + y1, x1 = 1;
            }
        }
        else
        {
            while(vis.find({x0, y0}) != vis.end())
            {
                if(y0 > 1) x0 += 3, y0 -= 3;
                else y0 = x0 + y0 + 2, x0 = 1;
            }
            vis.insert({x0, y0});
            cout << x0 << " " << y0 << "\n";
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