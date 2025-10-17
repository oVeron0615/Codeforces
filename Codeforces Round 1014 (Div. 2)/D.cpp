#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    s = "!" + s;

    vector<int> border; //같은 문자로 이루어진 구간이 끝나는 경계 index
    border.push_back(0);
    for(int i=1; i<n; i++)
        if(s[i] != s[i+1]) border.push_back(i);
    border.push_back(n);

    if(border.size() == 2) //index가 0과 n밖에 없다면 같은 문자로 이루어진 문자열
    {
        cout << -1 << "\n";
        return;
    }

    vector<int> ans;
    for(int i=border.size()-1; i>=1; i--)
    {
        int seg = border[i] - border[i-1]; //구간의 크기
        for(int j=0; j<seg*2; j++) //구간에 있는 문자와 다른 문자 2개를 seg개 만큼 각각 삽입한다.
            ans.push_back(i == 1 ? border[1] : border[i-1] + j);
    }

    cout << ans.size() << "\n";
    for(int a : ans) cout << a << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}