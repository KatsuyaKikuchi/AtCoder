#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

//! iから始まる文字列とjから始まる文字列の部分文字列が最長
ll dp[5005][5005];

int main()
{
    ll N;
    string S;
    cin >> N >> S;
    memset(dp, 0, sizeof(dp));
    for (int i = N - 1; i >= 0; --i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (S[i] != S[j])
                continue;
            dp[i][j] = 1;
            if (i + 1 < N && j + 1 < N && S[i + 1] == S[j + 1])
                dp[i][j] += std::min(dp[i + 1][j + 1], (ll)(i - j - 1));
        }
    }

    ll max = 0;
    REP(i, N)
    {
        REP(j, N)
        {
            max = std::max(max, dp[i][j]);
        }
    }
    cout << max << endl;
    return 0;
}