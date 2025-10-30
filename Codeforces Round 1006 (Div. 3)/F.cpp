#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6;
vector<int> cnt(MAXN + 1); //n!의 2의 약수의 개수

void init()
{
    for(int i=1; i<=MAXN; i++)
    {
        int tmp = i;
        cnt[i] = cnt[i - 1];
        while(tmp % 2 == 0) tmp /= 2, cnt[i]++;
    }
}

void solve()
{
    int n, k; cin >> n >> k;
    for(int i=1; i<=n; i++)
        cout << ((cnt[n - 1] == cnt[i - 1] + cnt[n - i]) ? k : 0) << " ";
    cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    init();

    int t; cin >> t;
    while(t--) solve();
}

/*
XOR 연산은 각 bit에 대해 독립이다. k의 임의의 비트 ki = 0이면 모든 T(i, j)의 ki = 0이다.
ki = 1일 경우, k를 홀수 번 만나면 ki = 1, 짝수 번 만나면 ki = 0이다.
이때, 주어진 T(i, j) 공식은 파스칼 삼각형 공식이다. 따라서 만난 횟수를 파스칼 삼각형 공식
(n - 1)C(r - 1)로 구할 수 있다.

(n - 1)C(r - 1) % 2가 구하고자 하는 답이다. nCr을 직접 구할 수도 있지만, 각 factorial이
2의 배수로 나누어 떨어지는 횟수를 구해, 분자의 횟수가 분모의 횟수와 같으면 홀수이고, 다르면
짝수임을 쉽게 알 수 있다.

factorial이 2의 배수로 나누어 떨어지는 횟수를 미리 전처리해 O(n)에 답을 구할 수 있다.
*/