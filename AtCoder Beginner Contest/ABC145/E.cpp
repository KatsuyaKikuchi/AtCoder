#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll A[3005];
ll dp[3005][3005][2];

int main()
{
    ll N, T;
    cin >> N >> T;
    REP(i, N)
    {
        cin >> A[i].first >> A[i].second;
    }
    // sort(A, A + N, [](pll a, pll b) { return a.first < b.first; });
    memset(dp, 0, sizeof(dp));

    REP(i, N)
    {
        REP(t, T + 1)
        {
            //! 普通に頼む
            {
                dp[i + 1][t][0] = std::max(dp[i][t][0], dp[i + 1][t][0]);
                if (t - A[i].first >= 0)
                    dp[i + 1][t][0] = std::max(dp[i + 1][t][0], dp[i][t - A[i].first][0] + A[i].second);
            }

            {
                dp[i + 1][t][1] = std::max(dp[i][t][1], dp[i + 1][t][1]);
                if (t - A[i].first >= 0)
                    dp[i + 1][t][1] = std::max(dp[i + 1][t][1], dp[i][t - A[i].first][1] + A[i].second);
            }
            //! ラストオーダー
            {
                dp[i + 1][t][1] = std::max(dp[i][t][1], dp[i + 1][t][1]);
                if (t < T)
                {
                    dp[i + 1][t][1] = std::max(dp[i + 1][t][1], dp[i][t][0] + A[i].second);
                }
            }
        }
    }

    ll max = 0;
    REP(i, T + 1)
    {
        max = std::max(max, dp[N][i][0]);
        if (i < T)
            max = std::max(max, dp[N][i][1]);
    }
    cout << max << endl;
    return 0;
}