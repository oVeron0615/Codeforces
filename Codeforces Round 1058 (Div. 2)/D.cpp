#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n; cin >> n;
    vector<int> a(2*n+1);
    vector<int> input1, input2;

    for(int i=1; i<=2*n; i++) //두 번째로 숫자가 나타나는 위치 찾기
    {
        input1.push_back(i);

        cout << "? " << input1.size() << " ";
        for(int j : input1) cout << j << " ";
        cout.flush();

        int res; cin >> res;
        if(res != 0)
        {
            a[i] = res;
            input2.push_back(i);
            input1.pop_back();
        }
    }

    for(int i=1; i<=2*n; i++) //첫 번째로 숫자가 나타나는 위치 찾기
    {
        if(a[i]) continue;

        cout << "? " << n + 1 << " " << i << " ";
        for(int j : input2) cout << j << " ";
        cout.flush();

        int res; cin >> res;
        a[i] = res;
    }

    cout << "! ";
    for(int i=1; i<=2*n; i++) cout << a[i] << " ";
    cout << "\n";
    cout.flush();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}