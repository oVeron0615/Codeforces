#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n; cin >> n;

    map<ll, ll> num_cnt;
    for(int i=1; i<=n; i++)
    {
        int ai; cin >> ai;
        num_cnt[ai]++;
    }

    vector<pll> cnt_num;
    for(auto [num, cnt] : num_cnt) cnt_num.push_back({cnt, num});
    sort(cnt_num.begin(), cnt_num.end(), greater()); //개수 순으로 내림차순 정렬

    ll Alice = 0, Bob = 0;
    bool is_turn_Alice = true;
    for(auto [cnt, num] : cnt_num)
    {
        Alice += cnt * ((num % 2 && is_turn_Alice ? num + 1 : num) / 2); //Alice 턴에 홀수 - 해당 수의 상한선까지 점수를 얻는다.
        Bob += cnt * ((num % 2 && !is_turn_Alice ? num + 1 : num) / 2); //Bob도 마찬가지
        if(num % 2) is_turn_Alice = !is_turn_Alice; //짝수일 때는 서로 점수를 반반씩 나눠가지므로, 홀수일 때만 생각하면 된다.
    }

    cout << Alice << " " << Bob << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}