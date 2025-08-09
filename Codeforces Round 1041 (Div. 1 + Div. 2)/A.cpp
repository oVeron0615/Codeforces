#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n; cin >> n;
    set<int> a;

    for(int i=1; i<=n; i++)
    {
        int ai; cin >> ai;
        a.insert(ai);
    }

    a.erase(-1);
    if(a.size() <= 1 && a.find(0) == a.end()) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}

/*
MEX가 0이 아니라면, min값은 0이기에 MEX = MAX여야 하지만 MEX의 정의로 인해 이 둘은 같을 수 없다.
따라서 MEX = 0이다.
MEX = 0이면 MAX = MIN이므로, 수열에 존재하는 모든 값은 -1 또는 0이 아닌 수로 동일해야 한다.
*/

/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n; cin >> n;
    bool check = true;
    int num = -1;

    for(int i=1; i<=n; i++)
    {
        int x; cin >> x;
        if(x == -1) continue;
        else
        {
            
            if(x == 0) check = false;
            else if(num == -1) num = x;
            else if(num != x) check = false;
        }
    }

    if(check) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}
*/