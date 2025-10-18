#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool is_prime(int num)
{
    if(num <= 1) return false;
    for(int i=2; i*i<=num; i++)
        if(num % i == 0) return false;
    return true;
}

void solve()
{
    int n; cin >> n;
    for(int i=n/3; i<=(2*n+2)/3; i++) //베르트랑 공준 : 2 이상의 x에 대하여 x < n < 2x를 만족하는 n에 하나 이상의 소수가 있다.
    {
        if(is_prime(i))
        {
            vector<int> ans;
            ans.push_back(i);

            int sub = 1;
            while(ans.size() < n) //소수를 찾고, 숫자를 적절히 배열하여 답을 만든다.
            {
                if(i - sub > 0) ans.push_back(i - sub);
                if(i + sub <= n) ans.push_back(i + sub);
                sub++;
            }

            for(auto a : ans) cout << a << " ";
            cout << "\n";
            return;
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