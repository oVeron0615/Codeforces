#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int score_cal(int ai)
{
    int score = 0;
    while(true) 
    {
        ai /= 2, score++;
        if(ai == 1) break;
        ai++;
    }
    return score;
}

void solve()
{
    int n, q; cin >> n >> q;

    vector<int> psum_score(n+1);
    vector<int> psum_diff(n+1);
    for(int i=1; i<=n; i++)
    {
        int ai; cin >> ai;

        psum_score[i] = psum_score[i-1] + score_cal(ai);
        psum_diff[i] = psum_diff[i-1] + (score_cal(ai) < score_cal(ai + 1));
    }

    while(q--)
    {
        int l, r; cin >> l >> r;
        cout << psum_score[r] - psum_score[l-1] + (psum_diff[r] - psum_diff[l-1]) / 2 << "\n";
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}

/*
Poby와 Rekkles 중 누가 먼저 수를 조작했느냐에 따라 점수가 달라질 수 있다.
만약 Rekkles가 먼저 조작했을 때가 Poby가 먼저 조작했을 때보다 점수가 더 커진다면, Poby는 이러한 수들을 먼저 조작해야만 할 것이다.
이때, 이러한 수들이 n개 있다면 먼저 조작 가능한 수는 (n/2의 올림)개이다.

구간 내의 점수, 위에서 설명한 수들의 개수를 부분합에 저장한다.
구간 쿼리가 나올 때마다 부분 합을 이용해 문제를 해결하면 된다.
*/