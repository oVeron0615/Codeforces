#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    bool is_forward = true;
    ll sz = 0;
    ll f_sum = 0, r_sum = 0;
    ll sum = 0;
    deque<ll> F, R;

    int q; cin >> q;
    for(int i=1; i<=q; i++)
    {
        int s; cin >> s;
        if(s == 1)
        {
            if(is_forward)
            {
                f_sum += sum - F.back() * sz;
                r_sum += -sum + R.front() * sz;
                F.push_front(F.back()); F.pop_back();
                R.push_back(R.front()); R.pop_front();
            }
            else
            {
                r_sum += sum - R.back() * sz;
                f_sum += -sum + F.front() * sz;
                R.push_front(R.back()); R.pop_back();
                F.push_back(F.front()); F.pop_front();
            }
        }
        else if(s == 2)
        {
            is_forward = !is_forward;
        }
        else if(s == 3)
        {
            ll k; cin >> k;
            if(is_forward)
            {
                f_sum += k * ++sz;
                r_sum += sum + k;
                F.push_back(k);
                R.push_front(k);
            }
            else
            {
                r_sum += k * ++sz;
                f_sum += sum + k;
                R.push_back(k);
                F.push_front(k);
            }
            sum += k;
        }

        cout << (is_forward ? f_sum : r_sum) << "\n";
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}

//2번 연산을 하나의 배열만 만들어서는 해결하기 어려우므로, 정방향 deque와 역방향 deque를 둘 다 만들었다.
//역방향 deque의 연산은 정방향과 반대임을 유의한다.